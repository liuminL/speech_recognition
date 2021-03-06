#pragma once
#include <string>
#include "ros/ros.h"
//#include "loadCfg.h"
#include "centre/event.h"

class hori_centreClient{
public:
    hori_centreClient(std::string nodeName,ros::NodeHandle *nodeHandle,void (* CallBackFun)(int eventID,void *p),void *p);
    ~hori_centreClient();

    std::string name;
    bool *isFeedBack;
private:

    ros::NodeHandle *n;
    ros::Publisher tocentrePub;
    ros::Subscriber centreFeedbackSub;
    ros::Rate *loopRate;

    bool isSetCallBack;
    void(*pCallBackFun)(int eventID,void *p);
    void *param;
    int currentState;
    int feedBackState;
    pthread_t pthread;

    void loadCfgFile(void);
public:
    void run(void);
    bool isfeedback(int eventID) const;
    void feedBackCome(int eventID);
public:
    void pubToCenter(int eventID);
    int checkFeedBack(void) const;
};
