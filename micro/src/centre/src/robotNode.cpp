#include "robotNode.h"

robotNode::robotNode(std::string nodeName,size_t index,int rate,centreParam *paramPointer,pubManager *pubManagerPointer,std::vector<resourceQueue *> *rcsqVectorPointer)
                                        :name(nodeName),nodeIndex(index),pcP(paramPointer),ppM(pubManagerPointer),pvprQ(rcsqVectorPointer){
    stateChanged = false;
    stateCheckTimeOut = rate * 5;//5s
    checkRate = new ros::Rate(rate);
    currentState = 0;
    stateCheckCount = 0;
    nodeState = 0;
    paused = false;
}

robotNode::~robotNode(){
    delete checkRate;
}

bool robotNode::isStateChanged(){
    if(stateChanged){
        stateChanged = false;
        return true;
    }
    else{
        checkRate->sleep();
        return false;
    }
}

bool robotNode::nodeStateCheck(){

    if(nodeState == 1 && paused == false){//pause
        ROS_INFO("[rN][%s]paused.",name.c_str());
        paused = true;
    }
    if(stateCheckCount == 0){
            if(nodeState == 2){
                ROS_INFO("[rN][%s]ON LINE.",name.c_str());
            }
        if(paused != true){
            nodeState = 0;//common
        }
    }
    if(nodeState == 0){
            if(paused == true){
                    ROS_INFO("[rN][%s]continued.",name.c_str());
                paused = false;
            }
        stateCheckCount ++;
    }
    if(stateCheckCount > stateCheckTimeOut && nodeState != 2){
        nodeState = 2;//lost
        ROS_INFO("[rN][%s]LOST!",name.c_str());
        ppM->setNodePublishState(0);
    }
}

void robotNode::action(){
    switch(pcP->nodeBehaviorSheet[currentState].action){
    case 0:
        doNoting(pcP->nodeBehaviorSheet[currentState].param1,pcP->nodeBehaviorSheet[currentState].param2,pcP->nodeBehaviorSheet[currentState].param3);
        break;
    case 1:
        askForResource(pcP->nodeBehaviorSheet[currentState].param1,pcP->nodeBehaviorSheet[currentState].param2,pcP->nodeBehaviorSheet[currentState].param3);
        break;
    case 2:
        executeMission(pcP->nodeBehaviorSheet[currentState].param1,pcP->nodeBehaviorSheet[currentState].param2,pcP->nodeBehaviorSheet[currentState].param3);
        break;
    case 3:
        finishMission(pcP->nodeBehaviorSheet[currentState].param1,pcP->nodeBehaviorSheet[currentState].param2,pcP->nodeBehaviorSheet[currentState].param3);
        break;
    case 4:
        changeState(pcP->nodeBehaviorSheet[currentState].param1,pcP->nodeBehaviorSheet[currentState].param2,pcP->nodeBehaviorSheet[currentState].param3);
        break;
    case 5:
        publishCommand(pcP->nodeBehaviorSheet[currentState].param1,pcP->nodeBehaviorSheet[currentState].param2,pcP->nodeBehaviorSheet[currentState].param3);
        break;
    }
    actionTranslate();
}

void robotNode::actionTranslate(){
    std::string actionName;
    switch(pcP->nodeBehaviorSheet[currentState].action){
    case 0:
        actionName = "do noting.";
        break;
    case 1:
        actionName = "ask for resource.";
        break;
    case 2:
        actionName = "execute mission.";
        break;
    case 3:
        actionName = "finish mission.";
        break;
    case 4:
        actionName = "change state.";
        break;
    case 5:
        actionName = "publish command.";
        break;
    default:
        actionName = "unknown action.";
        break;
    }
    if(pcP->nodeBehaviorSheet[currentState].describe != NULL){
        ROS_INFO("[rN][%s]action : %s [%s]",name.c_str(),actionName.c_str(),pcP->nodeBehaviorSheet[currentState].describe->c_str());
    }
    else{
        ROS_INFO("[rN][%s]action : %s [undefined]",name.c_str(),actionName.c_str());
    }
}

void robotNode::askForResource(int resourceID,int succeedID,int finishID){
    pvprQ->at(resourceID)->addMission(succeedID,finishID);
}

void robotNode::executeMission(int resourceID,int param2,int param3){
    pvprQ->at(resourceID)->executeOneMission();
}

void robotNode::finishMission(int resourceID,int param2,int param3){
    nodeState = 0;//common
    pvprQ->at(resourceID)->finishMission();
}

void robotNode::changeState(int resourceID, int state, int stateID){
    nodeState = state;
    ppM->setNodePublishState(stateID);
    //ROS_INFO("[rN][%s]nodeState change to [%d]",name.c_str(),nodeState);
}

void robotNode::publishCommand(int eventID, int param2, int param3){
    ppM->setNodePublishState(eventID);
}

std::string robotNode::getName(){
    return name;
}

void robotNode::changeState(int newState){
    stateCheckCount = 0;
    if(currentState != newState){
            //ROS_INFO("[rN][%s]state change %d -> %d",name.c_str(),currentState,newState);
        currentState = newState;
        stateChanged = true;
    }
}

void robotNode::run(){
    for(;;){

        if(isStateChanged()){
            //ROS_INFO("[rN][%s]before action",name.c_str());
            action();
        }
        else{
            nodeStateCheck();
            if( (pcP->nodeBehaviorSheet[currentState].action == 3 || pcP->nodeBehaviorSheet[currentState].action == 4)
               && nodeState == 0){//finish mission
                //ROS_INFO("[rN][%s]before idle execute",name.c_str());
                executeMission(pcP->nodeBehaviorSheet[currentState].param1,pcP->nodeBehaviorSheet[currentState].param2,pcP->nodeBehaviorSheet[currentState].param3);
            }
            ppM->nodePublish(nodeIndex);
        }
    }
}
