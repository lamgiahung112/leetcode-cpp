#include <bits/stdc++.h>
using namespace std;

map<int, bool> memo;
int nthUglyNumber(int n) {
    vector<int> dp (n, 0);
    int a = 0, b = 0, c = 0;
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[a]*2, min(dp[b]*3, dp[c]*5));
        
        if (dp[i] == dp[a]*2) a++;
        if (dp[i] == dp[b]*3) b++;
        if (dp[i] == dp[c]*5) c++;
    }
    return dp[n-1];
}

int main() {
    cout << nthUglyNumber(10);
}