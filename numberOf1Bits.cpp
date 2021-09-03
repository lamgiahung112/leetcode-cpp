#include <iostream>

using namespace std;

string findBinary(uint32_t n) {
    string ans = "";
    while (n != 0) {
        ans += to_string(n % 2);
        n /= 2;
    }
    return ans;
}

int hammingWeight(uint32_t n) {
    string binStr = findBinary(n);
    int ans = 0;
    for (int i = 0; i < binStr.size(); i++) {
        if (binStr[i] == '1') ans++;
    }
    return ans;
}

int main() {
    cout << hammingWeight(00000000000000000000000000001011);
}