#include <iostream>
#include <string>

using namespace std;

bool ok(const string & code) {
    if (code.size() > 14 || code.size() < 8) {
        return 0;
    }
    int symb = 0, up = 0, low = 0, fig = 0;

    for (char a: code) {
        if (a < 33 || a > 127) {
            return 0;
        }
        if ('0' <= a && a <= '9') {
            fig = 1;
        }
        else if ('A' <= a && a <= 'Z') {
            up = 1;
        }
        else if ('a' <= a && a <= 'z') {
            low = 1;
        }
        else {
            symb = 1;
        }
    }
    return (symb + up + low + fig >= 3);
}

int main() {
    string code;
    getline(cin, code);
    if (ok(code)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
