#ifndef CLOUD_SERVER_H
#define CLOUD_SERVER_H

#include "ComputeNode.h"

class CloudServer : public ComputeNode
{
public:
    CloudServer();

    bool canProcess(const Task &task) const override;
    void processTask(Task &task) override;
};

#endif
