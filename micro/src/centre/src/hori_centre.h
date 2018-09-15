#pragma once
#include <vector>
#include "ros/ros.h"
#include "includedMSG.h"
#include "centreParam.h"
#include "pubManager.h"
#include "robotNode.h"
#include "resourceQueue.h"

class horiCentre{
public:
    horiCentre(int argc, char **argv);
    ~horiCentre();
private:
    //ros subscriber
    ros::NodeHandle *n;
    ros::Subscriber tocentreSub;
    //robot node list
    std::vector<robotNode *> vprN;
    pthread_t *ppthreadt;
public:
    //parameter from configuration file
    centreParam cP;
    //publisher
    ros::Publisher centreFeedbackPub;
    pubManager *ppM;
    //resource queue
    std::vector<resourceQueue *> vprQ;
private:
    void allInit();
    void pubManagerInit();
    void resourceQueueInit();
    void robotNodeInit();
public:
    void msgProcess(int eventID);
    int run();
};

extern horiCentre *phoriCentre;
