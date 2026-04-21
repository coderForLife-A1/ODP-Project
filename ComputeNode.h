#ifndef COMPUTE_NODE_H
#define COMPUTE_NODE_H

#include "Task.h"

class ComputeNode
{
public:
    ComputeNode(int availableCPU, int currentLoad, int simulatedNetworkLatency)
        : availableCPU(availableCPU),
          currentLoad(currentLoad),
          simulatedNetworkLatency(simulatedNetworkLatency)
    {
    }

    virtual ~ComputeNode() = default;

    virtual int getAvailableCPU() const
    {
        return availableCPU;
    }

    virtual int getCurrentLoad() const
    {
        return currentLoad;
    }

    virtual int getSimulatedNetworkLatency() const
    {
        return simulatedNetworkLatency;
    }

    virtual bool canProcess(const Task &task) const = 0;

    virtual void processTask(Task &task)
    {
        task.setStatus(Task::Status::Processing);
    }

protected:
    int availableCPU;
    int currentLoad;
    int simulatedNetworkLatency;
};

#endif
