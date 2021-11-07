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

map<char, vector<string>> mp = {
    {'2', {"a", "b", "c"}},
    {'3', {"d", "e", "f"}},
    {'4', {"g", "h", "i"}},
    {'5', {"j", "k", "l"}},
    {'6', {"m", "n", "o"}}, 
    {'7', {"p", "q", "r", "s"}},
    {'8', {"t", "u", "v"}},
    {'9', {"w", "x", "y", "z"}}
};

vector<string> letterCombinations(string digits) {
    if (sz(digits) == 1) return mp[digits[0]];
    vector<string> s;
    for (auto l : mp[digits[0]]) {
        string suffix = digits.substr(1);
        for (auto v : letterCombinations(suffix)) {
            v = l + v;
            s.push_back(v);
        }
    }
    return s;
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    vector<string> s = letterCombinations("23");
    for (auto c : s) {
        cout << c << " ";
    }
}
