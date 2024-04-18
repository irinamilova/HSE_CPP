#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string text;
    string date;
    vector<string> workloads;
};

struct Worker {
    std::string name;
    std::string login;
    int maxLoad;
};

int getWorkerLoad(const vector<Task>& allTasks, const Worker& worker) {
    int totalLoad = 0;
    for (const auto& task : allTasks) {
        for (const auto& workload : task.workloads) {
            if (workload == worker.login) {
                totalLoad += stoi(workload);
            }
        }
    }
    return totalLoad;
}
