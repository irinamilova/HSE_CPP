#include <iostream>
using namespace std;
 
string ExtractDigits(const string& s) {
    string line;
    for (int x = 0; x != s.length(); ++x) {
        if (isdigit(s[x])) {
            line.push_back(s[x]);
        }
    }
    return line;
}
