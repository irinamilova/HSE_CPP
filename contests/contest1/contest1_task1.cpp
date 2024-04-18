//соображение №4. В программе нужно стараться избегать полных веток if -- else
//if(...) -> ... -> return;
// разделить на две подзадачиб для этого разработаем функцию, которая будет получать информацию о клетках и возвращать True/False
// The Zero overhead principle   you do not pay for that you do not use

#include <iostream>
#include <cmath>
#include <cstdint>


bool IsItQueenMove(int8_t x1, int8_t y1, int8_t x2, int8_t y2) 
{
    return (x1 == x2 || y1 == y2 || (abs(x1 - x2) == abs(y1 - y2)));
}

int main() {
    int8_t x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << (IsItQueenMove(x1, y1, x2, y2) ? "YES" : "NO");
    // if (IsItQueenMove(x1, y1, x2, y2))
    // {
    //     std::cout << "YES";
    //     return 0;
    // }
    // std::cout << "NO";
    return 0;
}