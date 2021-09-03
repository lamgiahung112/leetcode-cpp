#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isHappyUtil(int n, unordered_map<int, bool> memo) {
    if (memo[n]) return false;

    if (n == 1) return true;
    vector<int> digits;
    int cln = n;
    while (cln != 0) {
        digits.push_back(cln % 10);
        cln /= 10;
    }
    int newNumber = 0;
    for (auto digit: digits) {
        newNumber += digit * digit;
    }

    memo[n] = true;
    return isHappyUtil(newNumber, memo);
}

bool isHappy(int n) {
    unordered_map<int, bool> memo;
    return isHappyUtil(n, memo);
}

int main() {
    cout << isHappy(7);
}