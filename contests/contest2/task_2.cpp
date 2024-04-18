#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool palindrome(const string& s) {
    string str;

    for(char symb : s) {
        if (isalpha(symb)) {
            str.push_back(tolower(symb));
        }
    }
    int i = 0, j = str.size()-1;

    while(j > i) {
        if(str[i] != str[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    string std;
    getline(cin, std);

    if(palindrome(std)) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}
