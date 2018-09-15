//store parameter from configuration file
#pragma once
#include <vector>
#include <string>
#include "loadCfg.h"

class centreParam{
public:
    centreParam();
    ~centreParam();
private:

public:
    size_t maxID;
    int *ID2node;//mapping ID to node
    std::vector<std::string> nodeList;//store each node's name
    std::vector<std::string> rscList;//store each resource's name
public:
    nodeBehavior *nodeBehaviorSheet;
public:
    int loadConfigFile();
};
