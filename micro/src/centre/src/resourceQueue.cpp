#include "resourceQueue.h"

resourceQueue::resourceQueue(std::string rscName,size_t rscIndex,pubManager *pMpointer):name(rscName),index(rscIndex),ppM(pMpointer){
    missonQueue = new templateQueue<rscMission>(128);
}

resourceQueue::~resourceQueue(){
    delete missonQueue;
}

void resourceQueue::addMission(int startID,int finID){
    rscMission tempMission(startID,finID);
    missonQueue->pushBack(tempMission);
    ROS_INFO("[rQ]<%s> added Mission",name.c_str());
}

void resourceQueue::executeOneMission(void){
    if(missonQueue->isEmpty()){
        //ROS_INFO("[rQ]<%s> empty list to execute",name.c_str());
        return;
    }
    rscMission tempMission;
    missonQueue->check(tempMission);
    if(tempMission.getExe()){//executing
            //ROS_INFO("[rQ]<%s> a Mission is executing",name.c_str());
        return;
    }
    missonQueue->act((void *)0);//start mission
    ppM->setNodePublishState(tempMission.getStartID()); //publish start message
    ROS_INFO("[rQ]<%s> execute one Mission",name.c_str());
}

void resourceQueue::finishMission(void){
    if(missonQueue->isEmpty()){
        //ROS_INFO("[rQ]<%s> empty list to finish",name.c_str());
        return;
    }
    rscMission tempMission;
    missonQueue->check(tempMission);
    if(!tempMission.getExe()){//not executing
            ROS_INFO("[rQ]<%s> no Mission executing to finish",name.c_str());
        return;
    }
    missonQueue->popFront(tempMission);
    ppM->setNodePublishState(tempMission.getFinishID());//publish fin message
    ROS_INFO("[rQ]<%s> finish Mission",name.c_str());
}
