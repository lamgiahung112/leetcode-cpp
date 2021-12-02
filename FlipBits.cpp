#include <bits/stdc++.h>

using namespace std;

string getBinary (int n) {
    string ans = "";

    while (n) {
        char added = n % 2 == 0 ? '1' : '0';
        ans.insert(0, 1, added);
        n /= 2;
    }
    return ans;
}

int bitwiseComplement(int n) {
    string bin = getBinary(n);
    return stoi(bin, nullptr, 2);
}

int main() {
    cout << bitwiseComplement(5);
}