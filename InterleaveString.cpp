#include <bits/stdc++.h>
using namespace std;

bool dp[101][101][201];
    
bool canConstruct(string& s1, string& s2, string& s3, int i, int j, int k) {
    if (k == s3.size()) return (i == s1.size() && j == s2.size());

    if (dp[i][j][k]) return dp[i][j][k];

    bool _s1, _s2;
    if (i < s1.size() && s1[i] == s3[k]) {
        dp[i + 1][j][k + 1] = true;
        _s1 = canConstruct(s1, s2, s3, i + 1, j, k + 1);
        if (_s1) return true;
    }
    if (j < s2.size() && s2[i] == s3[k]) {
        dp[i][j + 1][k + 1] = true;
        _s2 = canConstruct(s1, s2, s3, i, j + 1, k + 1);
        if (_s2) return true;
    }
    return false;
}


bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    dp[0] = true;
    return canConstruct(s1, s2, s3);
}

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << isInterleave(s1, s2, s3);
}