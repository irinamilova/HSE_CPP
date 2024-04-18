#include <iostream>

int main() {
    int d, m, y;
    std::cin >> d >> m >> y;
    int num[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((y % 400 == 0 || y % 4 == 0 && y % 100 != 0)) {
        num[1] = 29;
    }
    d = d + 2;

    if (num[m-1] < d) {
        d = d - num[m-1];
        m = m + 1;
        if (m > 12) {
            m = 1;
            y = y + 1;
        }
    }
    std::cout << d << " " << m << " " << y << std::endl;
    return 0;
}
