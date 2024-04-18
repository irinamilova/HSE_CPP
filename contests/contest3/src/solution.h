
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

// // task 1
Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
{
    this->text = text;
    this->date = date;
    this->workloads = workloads;

}



struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
{
    this -> name = name;
    this -> login = login;
    this -> maxLoad = maxLoad;
}


// task 2
int Task::getTotalLoad() const
{
    int summa = 0;
    for (const auto &workload : workloads) {
        summa += workload.second;
    }
    return summa;
}

// task 3
void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
        if (t1.getTotalLoad() != t2.getTotalLoad()) {
            return t1.getTotalLoad() < t2.getTotalLoad();
        }
        if (t1.date != t2.date) {
            return t1.date < t2.date;
        }
        return t1.text < t2.text;
    });
}


// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int summa = 0;
    
    for (const Task& task : allTasks) {
        auto x = task.workloads.find(worker.login);
        if (x != task.workloads.end()) {
            summa = summa + x->second;
        }
    }
    return summa;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    tasks.push_back(newTask);

    for (const auto& worker : workers) {
        int summa = 0;
        for (const auto& task : tasks) {
            auto x = task.workloads.find(worker.login);
            if (x != task.workloads.end()) {
                summa += x->second;
            }
        }
        if (summa > worker.maxLoad) {
            tasks.pop_back();
            throw std::runtime_error("Overworked");
        }
    }
}



// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    tasks.push_back(newTask);
    std::vector<std::string> overworked;

    for (const auto& worker : workers) {
        int summa = 0;
        for (const auto& task : tasks) {
            auto x = task.workloads.find(worker.login);
            if (x != task.workloads.end()) {
                summa += x->second;
            }
        }
        if (summa > worker.maxLoad) {
            overworked.push_back(worker.login);
        }
    }
    if (!overworked.empty()) {
        std::sort(overworked.begin(), overworked.end());
        std::string error = "Overworked: ";
        for (size_t i = 0; i < overworked.size(); ++i) {
            for (const auto& worker : workers) {
                if (worker.login == overworked[i]) {
                    int curr = 0;
                    for (const auto& task : tasks) {
                        auto x = task.workloads.find(worker.login);
                        if (x != task.workloads.end()) {    
                            curr += x->second;
                        }
                    }
                    int summa = curr - worker.maxLoad;
                    error += worker.login + " by " + std::to_string(summa);
                    if (i != overworked.size() - 1) {
                        error += ", ";
                    }
                    break;
                }
            }
        }
        throw std::runtime_error(error);
    }
}