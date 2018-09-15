#pragma once
#include "ros/ros.h"
#include "centreParam.h"
#include "includedMSG.h"

class pubManager{
public:
    pubManager(centreParam *cPpointer,ros::Publisher *pP);
    ~pubManager();
private:
    centreParam *pcP;
    ros::Publisher *pubP;
    int *nodeEventList;
public:
    void publishAnEventID(int eventID);
    void setNodePublishState(int eventID);
    void nodePublish(size_t nodeindex);
};
