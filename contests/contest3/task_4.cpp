#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join(const vector<string>& tokens, char delimiter) {
    string line;
    for (int x = 0; x < tokens.size(); x++) {
        line += tokens[x];

        if (x != tokens.size()-1) {
            line += delimiter;
        }
    }
    return line;
}
