#include <bits/stdc++.h>

using namespace std;

vector<int> fairCandySwap(vector<int> aliceSizes, vector<int> bobSizes) {
    map<int, bool> alice;
    map<int, bool> bob;

    int diff;
    int total_b = 0, total_a = 0;

    for (auto s : aliceSizes) {
        alice[s] = true;
        total_a += s;
    }
    for (auto s : bobSizes) {
        bob[s] = true;
        total_b += s;
    }
    diff = (total_a - total_b) / 2;
    vector<int> ans;
    for (auto s : aliceSizes) {
        int tmp = s - diff;
        if (bob[s - diff]) {
            ans = {s, s - diff};
            break;
        }
    }
    return ans;
}

int main() {
    fairCandySwap({1,2,5}, {2,4});
}