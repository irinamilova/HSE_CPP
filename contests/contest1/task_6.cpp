#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << "\t";

    for (int i = 1; i <= n; i++) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    for (int i = 1; i <= n; i++) {
        std::cout << i << "\t";

        for (int k = 1; k <= n; k++) {
            int r = (i * k) % m;
            std::cout << r << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}