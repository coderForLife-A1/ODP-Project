#include "CloudServer.h"
#include <iostream>

CloudServer::CloudServer()
    : ComputeNode(1000, 0, 150)
{
}

bool CloudServer::canProcess(const Task &task) const
{
    return task.getMaxTolerableLatency() >= simulatedNetworkLatency;
}

void CloudServer::processTask(Task &task)
{
    std::cout << "CloudServer processing task " << task.getTaskID()
              << " with simulated latency " << simulatedNetworkLatency << " ms.\n";
    task.setStatus(Task::Status::Processing);
    task.setStatus(Task::Status::Completed);
}
