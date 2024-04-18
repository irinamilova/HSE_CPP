#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    string line;
    vector<string> ans;

    for (char x : str) {
        if (x == delimiter) {
            ans.push_back(line);
            line = "";
        }
        else {
            line = line + x;
        }
    }
    ans.push_back(line);
    return ans;
}
