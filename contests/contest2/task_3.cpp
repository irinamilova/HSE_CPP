#include <iostream>
#include <string>
#include <map>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;

    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& t, const std::string& d, const std::map<std::string, int>& w) : text(t), date(d), workloads(w) {}
};

struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& n, const std::string& l, int m) : name(n), login(l), maxLoad(m) {}
};

int main() {
    // Example of creating Task and Worker objects using the constructors
    std::map<std::string, int> workloads = {{"daniel", 5}, {"m_gump", 10}};
    Task task("merge new feature", "2023-05-10", workloads);
    Worker worker("John Doe", "jdoe123", 40);

    return 0;
}
