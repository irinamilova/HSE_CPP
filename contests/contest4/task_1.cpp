#include <iostream>
#include <string>

using namespace std;

struct Task {
    string text, date;
    int workloads;
    Task(string t, string d, int wl) : text(t), date(d), workloads(wl) {}
};

struct Worker {
    string name, login;
    int maxLoad;
    Worker(string n, string l, int ml) : name(n), login(l), maxLoad(ml) {}
};
