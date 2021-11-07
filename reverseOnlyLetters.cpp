#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isLetter(char& s) {
    if (s - 'A' >= 0 && s - 'A' <= 25) return true;
    if (s - 'a' >= 0 && s - 'a' <= 25) return true;
    return false;
}

string reverseOnlyLetters(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (isLetter(s[left]) && isLetter(s[right])) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
            continue;
        }
        if (!isLetter(s[left])) {
            left++;
        }
        if (!isLetter(s[right])) {
            right--;
        }
    }
    return s;
}

int main() {

}