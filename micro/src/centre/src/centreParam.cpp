#include <stdlib.h>
#include <memory.h>
#include "ros/ros.h"
#include "centreParam.h"

centreParam::centreParam(){
}

centreParam::~centreParam(){
    delete[] ID2node;
    delete[] nodeBehaviorSheet;
    nodeList.clear();
    rscList.clear();
}

int centreParam::loadConfigFile(){
    std::string path = getenv("HOME");
    path += "/centreCfg/centreCfg.json";
    //ROS_INFO("load file");
    loadCfg load(path);
    ROS_INFO("read %s done",path.c_str());
    maxID = load.getMaxID();
    ID2node = new int[maxID];
    memset(ID2node,0,maxID * sizeof(int));
    nodeBehaviorSheet = new nodeBehavior[maxID];
    memset(nodeBehaviorSheet,0,maxID * sizeof(nodeBehavior));
    load.getParam(ID2node,rscList,nodeList,nodeBehaviorSheet);
}

