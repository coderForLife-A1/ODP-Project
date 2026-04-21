#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include <memory>
#include <vector>

#include "ComputeNode.h"

class LoadBalancer
{
public:
    void addNode(const std::shared_ptr<ComputeNode> &node);
    bool routeTask(Task &task);

private:
    std::vector<std::shared_ptr<ComputeNode>> nodePool;
};

#endif
