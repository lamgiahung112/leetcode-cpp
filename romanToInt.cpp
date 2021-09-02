#include <iostream>
#include <string>

int romanToInt(std::string s) {
    int ans = 0;
    int len = s.length();

    if (len == 1) {
        if (s == "I") return 1;
        if (s == "V") return 5;
        if (s == "X") return 10;
        if (s == "L") return 50;
        if (s == "C") return 100;
        if (s == "D") return 500;
        if (s == "M") return 1000;
    }

    int i = 0;

    while (i < len) {
        if (s[i] == 'I' && s[i + 1] == 'V') {
            ans += 4;
            i += 2;
        }
        else if (s[i] == 'I' && s[i + 1] == 'X') {
            ans += 9;
            i += 2;

        } 
        else if (s[i] == 'X' && s[i + 1] == 'L') {
            ans += 40;
            i += 2;
        }
        else if (s[i] == 'X' && s[i + 1] == 'C') {
            ans += 90;
            i += 2;

        }
        else if (s[i] == 'C' && s[i + 1] == 'D') {
            ans += 400;
            i += 2;

        }
        else if (s[i] == 'C' && s[i + 1] == 'M') {
            ans += 900;
            i += 2;
        }
        else {
            if (s[i] == 'I') ans += 1;
            if (s[i] == 'V') ans += 5;
            if (s[i] == 'X') ans += 10;
            if (s[i] == 'L') ans += 50;
            if (s[i] == 'C') ans += 100;
            if (s[i] == 'D') ans += 500;
            if (s[i] == 'M') ans += 1000;
            i++;
        }
    }
    return ans;
}

int main() {
    std::cout << romanToInt("MMMXLV");
}