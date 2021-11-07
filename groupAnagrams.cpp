#include <bits/stdc++.h>

#define ff first
#define ss second
#define ll long long

#define pb push_back
#define sz(x) int(x.size())

#define forf(i, a, b) for(int i = a; i <= b; ++i)
#define forb(i, b, a) for(int i = b; i >= a; --i)

using namespace std;
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> pli;

const int MOD = 1000000007;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> hash;
    vector<vector<string>> ans;

    forf(i, 0, sz(strs) - 1) {
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        hash[tmp].push_back(strs[i]);
    }
    for (auto s : hash) {
        ans.push_back(s.second);
    }
    return ans;
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    vector<string> tests = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams(tests);
    for (auto v : res) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}
