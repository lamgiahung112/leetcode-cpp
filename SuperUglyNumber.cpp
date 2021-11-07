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

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> dp (n, 0);
    vector<int> tmp (primes.size(), 1);
    
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
        int m = INT_MAX;
        
        for (int j = 0; j < primes.size(); j++) {
            m = min(m, tmp[j]*primes[j]);
        }
        dp[i] = m;
        for (int j = 0; j < primes.size(); j++) {
            if (dp[i] == tmp[j]*primes[j]) {
                tmp[j]++;
            }
        }
    }
    return dp[n-1];
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    vector<int> primes = {2,7,13,19};
    cout << nthSuperUglyNumber(12, primes);
}
