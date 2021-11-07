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

vector<string> generateParenthesisUtil(int n, int open, int close, string current = "") {
    if (open == 0 && close == 0) return {current};

    if (open == close) {
        return generateParenthesisUtil(n, open - 1, close, current + "(");
    } else {
        vector<string> v1;
        vector<string> v2;
        if (open > 0) {
            v1 = generateParenthesisUtil(n, open - 1, close, current + "(");
        }
        if (close > 0) {
            v2 = generateParenthesisUtil(n, open, close - 1, current + ")");
        }

        for (auto v : v2) {
            v1.push_back(v);
        }
        return v1;
    }
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    vector<string> s = generateParenthesisUtil(3, 3, 3, "");
    for (auto v : s) {
        cout << v << " ";
    }
}
