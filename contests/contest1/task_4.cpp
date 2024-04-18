#include <iostream>
 
int main() {
    int n;
    float s = 1, ans;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        ans = ans + s / i;
        s = -1 * s;
    }
    std::cout << ans;
}