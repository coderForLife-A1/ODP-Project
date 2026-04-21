#include "EdgeDevice.h"

#include <iostream>

EdgeDevice::EdgeDevice()
    : ComputeNode(10, 0, 5)
{
}

bool EdgeDevice::canProcess(const Task &task) const
{
    return task.getRequiredCycles() <= availableCPU;
}

void EdgeDevice::processTask(Task &task)
{
    std::cout << "EdgeDevice processing task " << task.getTaskID()
              << " with simulated latency " << simulatedNetworkLatency << " ms.\n";
    task.setStatus(Task::Status::Processing);
    task.setStatus(Task::Status::Completed);
}
