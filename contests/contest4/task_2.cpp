#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Worker {
    string name;
    string login;
    int maxLoad;
};

struct Task {
    string text;
    string date;
    vector<Worker> workloads;

    int getTotalLoad() {
        int totalLoad = 0;
        for (const auto& worker : workloads) {
            totalLoad += worker.maxLoad;
        }
        return totalLoad;
    }
};