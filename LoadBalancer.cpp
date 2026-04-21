#include "LoadBalancer.h"

#include <iostream>

void LoadBalancer::addNode(const std::shared_ptr<ComputeNode> &node)
{
    nodePool.push_back(node);
}

bool LoadBalancer::routeTask(Task &task)
{
    for (const auto &node : nodePool)
    {
        if (node != nullptr && node->canProcess(task))
        {
            node->processTask(task);
            return true;
        }
    }

    std::cerr << "Warning: no compute node could process task " << task.getTaskID() << ".\n";
    return false;
}
