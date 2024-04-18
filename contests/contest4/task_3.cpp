#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string text;
    string date;
    int totalLoad;
};

bool compareTasks(const Task& task1, const Task& task2) {
    if (task1.totalLoad != task2.totalLoad) {
        return task1.totalLoad < task2.totalLoad;
    }
    if (task1.date != task2.date) {
        return task1.date < task2.date;
    }
    return task1.text < task2.text;
}

void sortTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), compareTasks);
}
