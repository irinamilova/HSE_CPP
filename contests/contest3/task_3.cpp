#include <iostream>
#include <string>

using namespace std;

string common_suffix(const string& a, const string& b) {
    string line;
    int x = a.size()-1, y = b.size()-1;

    while (a[x] == b[y] && x >= 0 && y >= 0) {
        line = a[x] + line;
        x--;
        y--;
    }
    return line;
}