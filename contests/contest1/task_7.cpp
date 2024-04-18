#include <iostream>

int main() {
    for (int i = 0; i <= 15; i++) {
        std::cout << "\t" <<std::hex << std::uppercase << i;
    }

    std::cout << std::endl;

    for (int i = 2; i <= 7; i++) {
        std::cout << std::hex << std::uppercase << i << "\t";

        for (int k = 0; k < 16; ++k) {
            int ascii = k + 16 * i;

            if (ascii < 32 || ascii > 127) {
                std::cout << "\t";
            }
            else if(k != 0) {
                std::cout << "\t" << char(ascii);
            }
            else {
                std::cout << char(ascii);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
