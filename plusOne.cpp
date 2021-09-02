#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int i = digits.size() - 1;
    if (i == 0 && digits[i] != 9) {
        digits[i]++;
        return digits;
    }

    bool canStop = false;

    while (i >= 0 && !canStop) {
        if (digits[i] == 9) {
            digits[i] = 0;
            i--;
        } else {
            digits[i]++;
            canStop = true;
        }
    }

    if (i < 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main() {
    vector<int> digits = {9,9,9};
    digits = plusOne(digits);
    for (auto item: digits) {
        cout << item << endl;
    }
}