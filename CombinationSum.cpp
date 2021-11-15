#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<vector<int>>> dp (target + 1);

    dp[0] = {{}};

    for (auto cand : candidates) {
        for (int i = 0; i <= target; i++) {
            int nxtIdx = i + cand;
            if (nxtIdx <= target) {
                for (auto seq : dp[i]) {
                    seq.push_back(cand);
                    dp[nxtIdx].push_back(seq);
                }
            }
        }
    }
    return dp[target];
}

int main() {

}