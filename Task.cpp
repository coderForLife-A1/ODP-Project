#include "Task.h"

Task::Task(int taskID, int requiredCycles, int maxTolerableLatency)
    : taskID(taskID),
      requiredCycles(requiredCycles),
      maxTolerableLatency(maxTolerableLatency),
      status(Status::Pending) {}

int Task::getTaskID() const
{
    return taskID;
}

int Task::getRequiredCycles() const
{
    return requiredCycles;
}

int Task::getMaxTolerableLatency() const
{
    return maxTolerableLatency;
}

Task::Status Task::getStatus() const
{
    return status;
}

void Task::setStatus(Status newStatus)
{
    status = newStatus;
}
