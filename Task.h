#ifndef TASK_H
#define TASK_H

class Task
{
public:
    enum class Status
    {
        Pending,
        Processing,
        Completed
    };

    Task(int taskID, int requiredCycles, int maxTolerableLatency);

    int getTaskID() const;
    int getRequiredCycles() const;
    int getMaxTolerableLatency() const;
    Status getStatus() const;

    void setStatus(Status newStatus);

private:
    int taskID;
    int requiredCycles;
    int maxTolerableLatency;
    Status status;
};

#endif
