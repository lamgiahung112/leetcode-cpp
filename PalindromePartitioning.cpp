#include <bits/stdc++.h>

using namespace std;
// basic and slow
// map<int, vector<vector<string>>> mp;

bool isPalin(string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

// vector<vector<string>> helper(string& s, int l) {
//     if (l == s.size()) return {{}};
//     if (l > s.size()) return {};
//     if (mp[l].size()) return mp[l];

//     vector<vector<string>> ans;
//     for (int i = l; i < s.size(); i++) {
//         if (isPalin(s, l, i)) {
//             vector<vector<string>> suffixWays = helper(s, i + 1);
//             for (auto v : suffixWays) {
//                 v.insert(v.begin(), s.substr(l, i - l + 1));
//                 ans.push_back(v);
//             }
//         }
//     }
//     mp[l] = ans;
//     return ans;
// }

// vector<vector<string>> partition(string s) {
//     return helper(s, 0);
// }

// backtrack to generate subsets

void generateSubsets(string& s, int i, vector<string>& path, vector<vector<string>>& ans) {
    if (i == s.size()) {
        ans.push_back(path);
    }
    else {
        for (int j = i; j < s.size(); j++) {
            auto tmp = s.substr(i, j - i + 1);
            if (s[i] == s[j] && isPalin(s, i, j)) {
                path.push_back(tmp);
                generateSubsets(s, j + 1, path, ans);
                path.pop_back();
            }
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    generateSubsets(s, 0, path, ans);
    return ans;
}

int main() {
    string test = "cdd";
    partition(test);
}