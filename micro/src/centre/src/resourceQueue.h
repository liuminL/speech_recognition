#pragma once
#include <string>
#include "ros/ros.h"
#include "templateQueue.h"
#include "pubManager.h"
#include "includedMSG.h"

class rscMission{
public:
    rscMission():startID(0),finishID(0),isExecuting(false){}
    rscMission(int start,int fin):startID(start),finishID(fin),isExecuting(false){}
    ~rscMission(){}
private:
    bool isExecuting;
    int startID;//publish when start
    int finishID;//publish when finish
public:
    void copyFrom(rscMission src){
        isExecuting = src.getExe();
        startID = src.getStartID();
        finishID = src.getFinishID();
    }
    void checkTo(rscMission &dst){
        dst.copyFrom(*this);
    }
    void action(void *p){
        switch((long int) p ){
        case 0 ://set execute
            isExecuting = true;
            break;
        }
    }
    bool getExe() const{return isExecuting;}
    int getStartID() const{return startID;}
    int getFinishID() const{return finishID;}
    void setMission(int start,int fin){
        isExecuting = false;
        startID = start;
        finishID = fin;
    }
};

class resourceQueue{
public:
    resourceQueue(std::string rscName,size_t rscIndex,pubManager *pMpointer);
    ~resourceQueue();
private:
    std::string name;
    size_t index;
    pubManager *ppM;
    templateQueue<rscMission> *missonQueue;
public:
    void addMission(int startID,int finID);
    void executeOneMission(void);
    void finishMission(void);
};
