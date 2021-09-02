#include <iostream>
#include <string>

using namespace std;

int reverse(int x) {
    bool isSigned = (x < 0) ? 1 : 0;
    long long y = x;
    if (isSigned) y *= -1;
    string s = to_string(y);
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    y = stoll(s);
    if (y < INT_MIN || y > INT_MAX) {
        return 0;
    }
    x = y;
    return (isSigned) ? -x : x;
}

int main() {
    
}