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

int numDecodings(string s) {
    vector<int> dp (sz(s) + 1, 0);
    dp[sz(s)] = 1;

    forb(i, sz(s), 0) {
        if (s[i] != '0') {
            dp[i] += dp[i+1];
        }

        if (i < sz(s)-1) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26) {
                dp[i] += dp[i+2];
            }
        }
    }
    return dp[0];
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
}
