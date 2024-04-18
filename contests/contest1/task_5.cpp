#include <iostream>

using namespace std;

int main() {
    int n, k, m, s, ans = 0;
    cin >> m >> n >> k;

    while (n >= k && m >= n) {
        s = (n/k) * (m/n);
        m = m - k*s;
        ans += s;
    }

    cout << ans;
    return 0;
}
