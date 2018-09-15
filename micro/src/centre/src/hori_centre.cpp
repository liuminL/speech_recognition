#include <pthread.h>
#include "hori_centre.h"

horiCentre *phoriCentre;
void tocentreCallback(const centre::event::ConstPtr& msg){
    //ROS_INFO("I heard [%d]",msg->eventID);
    phoriCentre->msgProcess(msg->eventID);
}

void *robotNodeThread(void *arg){
    ROS_INFO("[rN][%s] run",((robotNode *)arg)->name.c_str());
    ((robotNode *)arg)->run();
    return NULL;
}

horiCentre::horiCentre(int argc, char **argv){
    ros::init(argc, argv, "horiCentre");
    n = new ros::NodeHandle;
    centreFeedbackPub = n->advertise<centre::event>("centreFeedback", 100);
    tocentreSub = n->subscribe("tocentre", 100, tocentreCallback);
    phoriCentre = this;//global pointer
}

horiCentre::~horiCentre(){
    delete n;
    vprN.clear();
    delete[] ppthreadt;
    vprQ.clear();
}

void horiCentre::allInit(){
    cP.loadConfigFile();
    pubManagerInit();
    resourceQueueInit();
    robotNodeInit();
}

void horiCentre::pubManagerInit(){
    ppM = new pubManager(&cP,&centreFeedbackPub);
}

void horiCentre::resourceQueueInit(){
    resourceQueue * tempprQ;
    for(size_t i = 0;i < cP.rscList.size();i ++){
        tempprQ = new resourceQueue(cP.rscList.at(i),i,ppM);
        vprQ.push_back(tempprQ);
    }
}

void horiCentre::robotNodeInit(){
    robotNode * tempprN;
    ppthreadt = new pthread_t[cP.nodeList.size()];
    for(size_t i = 0;i < cP.nodeList.size();i ++){
            ROS_INFO("creating node [%s]",cP.nodeList.at(i).c_str());
        tempprN = new robotNode(cP.nodeList.at(i),i,50,&cP,ppM,&vprQ);
        vprN.push_back(tempprN);
        int error = pthread_create(&ppthreadt[i],NULL,robotNodeThread,(void *)vprN.at(i));
        if(error!=0)
        {
            ROS_INFO("pthread_create is not created ... ");
            return;
        }
    }
}

void horiCentre::msgProcess(int eventID){
    if(eventID > cP.maxID){
        ROS_INFO("[hC][warning]got a out of scale:(%d) ID:(%d) , ignored.",cP.maxID,eventID);
        return;
    }
    vprN.at(cP.ID2node[eventID])->changeState(eventID);
}

int horiCentre::run(){
    allInit();
    ROS_INFO("Start spin");
    //ros::Rate loop_rate(1);
//    while (ros::ok()){
//
//        ros::spinOnce();
//        //loop_rate.sleep();
//    }
    ros::spin();
}
