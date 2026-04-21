#include <iostream>
#include <memory>
#include <vector>

#include "CloudServer.h"
#include "EdgeDevice.h"
#include "LoadBalancer.h"
#include "Task.h"

int main()
{
    LoadBalancer loadBalancer;

    const auto statusToString = [](Task::Status status)
    {
        switch (status)
        {
        case Task::Status::Pending:
            return "Pending";
        case Task::Status::Processing:
            return "Processing";
        case Task::Status::Completed:
            return "Completed";
        }

        return "Unknown";
    };

    loadBalancer.addNode(std::make_shared<EdgeDevice>());
    loadBalancer.addNode(std::make_shared<EdgeDevice>());
    loadBalancer.addNode(std::make_shared<CloudServer>());

    std::vector<Task> tasks;
    tasks.emplace_back(1, 5, 10);    // Lightweight, urgent: should fit an EdgeDevice
    tasks.emplace_back(2, 750, 500); // Heavy, relaxed latency: should fit CloudServer
    tasks.emplace_back(3, 600, 20);  // Heavy, urgent: should fail both nodes
    tasks.emplace_back(4, 8, 5);     // Very small but latency-sensitive: should fit an EdgeDevice
    tasks.emplace_back(5, 300, 150); // Moderate load, cloud-friendly latency: should fit CloudServer

    for (auto &task : tasks)
    {
        std::cout << "Routing task " << task.getTaskID()
                  << " [cycles=" << task.getRequiredCycles()
                  << ", maxLatency=" << task.getMaxTolerableLatency() << " ms]...\n";

        const bool routed = loadBalancer.routeTask(task);

        std::cout << "Result: " << std::boolalpha << routed
                  << ", final status=" << statusToString(task.getStatus()) << "\n\n";
    }

    return 0;
}
