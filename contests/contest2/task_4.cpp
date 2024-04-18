#include <iostream>
#include <string>

using namespace std;

string soundex(const string& str) {
    string code;
    code = code + str[0];
    for (int i = 1; i < str.length(); i++) {
        char symb = str[i];
        if (symb == 'a' || symb == 'e' || symb == 'h' || symb == 'i' || symb == 'o' || symb == 'u' || symb == 'w' || symb == 'y') {
            continue;
        }
        if (symb == 'b' || symb == 'f' || symb == 'p' || symb == 'v') {
            code = code + '1';
        }
        else if (symb == 'c' || symb == 'g' || symb == 'j' || symb == 'k' || symb == 'q' || symb == 's' || symb == 'x' || symb == 'z') {
            code = code + '2';
        }
        else if (symb == 'd' || symb == 't') {
            code = code + '3';
        }
        else if (symb == 'l') {
            code = code + '4';
        }
        else if (symb == 'm' || symb == 'n') {
            code = code + '5';
        }
        else if (symb == 'r') {
            code = code + '6';
        }
    }
    string neww;
    for (int i = 0; i < code.size(); i++) {
        if (code[i-1] != code[i] || i == 0) {
            neww = neww + code[i];
        }
    }
    while (neww.size() < 4) {
        neww = neww + '0';
    }
    if (neww.size() > 4) {
        neww = neww.substr(0, 4);
    }
    return neww;
}

int main() {
    string str;
    cin >> str;
    string code = soundex(str);
    cout << code;
    return 0;
}
