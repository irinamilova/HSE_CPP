#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> pi(n);
    
    for (int x = 0; x < n; x++) {
        cin >> pi[x];
    }

    vector<int> pi_1(n);

    for (int x = 0; x < n; x++) {
        pi_1[pi[x]-1] = x + 1;
    }

    for (int x = 0; x < n; x++) {
        cout << pi_1[x] << " ";
    }
    return 0;
}