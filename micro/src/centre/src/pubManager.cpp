#include "pubManager.h"
pubManager::pubManager(centreParam* cPpointer, ros::Publisher* pP):pcP(cPpointer),pubP(pP){
    nodeEventList = new int[pcP->nodeList.size()];
    memset(nodeEventList,0,pcP->nodeList.size() * sizeof(int));
}

pubManager::~pubManager(){
    delete [] nodeEventList;
}

void pubManager::publishAnEventID(int eventID){
    centre::event msg;
    msg.eventID = eventID;
    pubP->publish(msg);
}

void pubManager::setNodePublishState(int eventID){
    nodeEventList[pcP->ID2node[eventID]] = eventID;
    publishAnEventID(eventID);
}

void pubManager::nodePublish(size_t nodeindex){
    publishAnEventID(nodeEventList[nodeindex]);
}
