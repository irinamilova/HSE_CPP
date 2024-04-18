#include <iostream>
#include <string>

using namespace std;

string adding(string n) {
    int var = 1;
    for (int i = n.size() - 1; i >= 0; i--) {
        int d = var + n[i] - '0';
        n[i] = (d % 10) + '0';
        var = d / 10;
    }
    if (var) {
        n = "1" + n;
    }
    return n;
}

int main() {
    string n;
    cin >> n;
    string res = adding(n);
    cout << res;
    return 0;
}
