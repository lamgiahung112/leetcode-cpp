#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount, int num = 0) {
    vector<int> dp (amount + 1, 0);
    dp[0] = 0;

    for (int i = 0; i <= amount; i++) {
        if (dp[i] == 0 && i != 0) continue;

        for (auto c : coins) {
            if (i + c <= amount) {
                if (dp[i+c] == 0 || dp[i+c] > dp[i] + 1) {
                    dp[i+c] = dp[i] + 1;
                }
            }
        }
    }
    return dp[amount];
}

int main() {}