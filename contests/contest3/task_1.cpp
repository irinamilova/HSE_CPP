#include <iostream>
#include <fstream>

using namespace std;

void count(istream& file, int& letters, int& words, int& lines) {
    letters = 0, words = 0, lines = 0;
    char a;
    bool LinW = false;

    while (file.get(a)) {
        if (isalpha(a)) {
            letters++;
            if (!LinW) {
                LinW = true;
                words++;
            }
        }
        else if (a == '\n') {
            lines++;
            LinW = false;
        }
        else if (isspace(a)) {
            LinW = false;
        }
        else if (isdigit(a)) {
            LinW = false;
        }
        else  {
            LinW = false;
        }
    }
    if (LinW) {
        words++;
    }
}

int main() {
    ifstream file("input.txt");
    int letters, words, lines;
    count(file, letters, words, lines);

    cout << "Input file contains: \n";
    cout << letters << " letters \n";
    cout << words << " words \n";
    cout << lines << " lines";
    return 0;
}
