#include <iostream>
#include <string>

using namespace std;

int main() {
    int k, r = 0;
    string n;
    cin >> k >> n;

    for (int i = 0; i < n.size(); i++) {
        r = (r*10 + (n[i] - '0')) % k;
    }
    cout << r;
    return 0;
}
