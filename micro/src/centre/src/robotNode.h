#pragma once
#include <string>
#include <vector>
#include "ros/ros.h"
#include "centreParam.h"
#include "pubManager.h"
#include "resourceQueue.h"

class robotNode{
public:
    robotNode(std::string nodeName,size_t index,int rate,centreParam *paramPointer,pubManager *pubManagerPointer,std::vector<resourceQueue *> *rcsqVectorPointer);
    ~robotNode();
    std::string name;
    size_t nodeIndex;
private:
    ros::Rate *checkRate;
    centreParam *pcP;
    pubManager *ppM;
    std::vector<resourceQueue *> * pvprQ;
    //horiCentre *phC;
    bool stateChanged;//judge from client
    int currentState;//get from client

    int stateCheckCount;//
    int stateCheckTimeOut;
    int nodeState;//0:common 1:pause 2:lost
    bool paused;
private:
    bool isStateChanged();
    bool nodeStateCheck();
    void action();
    void actionTranslate(void);
    //actionFunc count = 6
    void doNoting(int param1,int param2,int param3){return;}        //0
    void askForResource(int resourceID,int succeedID,int finishID);   //1
    void executeMission(int resourceID,int param2,int param3);       //2
    void finishMission(int resourceID,int param2,int param3);           //3
    void changeState(int resourceID,int state,int stateID);                  //4
    void publishCommand(int eventID,int param2,int param3);         //5
    //actionFunc finish
public:
    std::string getName();
    void changeState(int newState);
    void run();
};
