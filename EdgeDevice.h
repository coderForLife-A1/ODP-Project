#ifndef EDGE_DEVICE_H
#define EDGE_DEVICE_H

#include "ComputeNode.h"

class EdgeDevice : public ComputeNode
{
public:
    EdgeDevice();

    bool canProcess(const Task &task) const override;
    void processTask(Task &task) override;
};

#endif
