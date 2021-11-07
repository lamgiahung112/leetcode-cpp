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

int minDistance(string word1, string word2) {
    vector<vector<int>> dp (sz(word1) + 1, vector<int> (sz(word2) + 1, 0));

    forf(i, 0, sz(word1)) {
        forf(j, 0, sz(word2)) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else {
                int cost = 1;
                if (word1[i-1] == word2[j-1]) cost = 0;

                // edit distance of insert op and remove op
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                // edit distance of modify op
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cost);
            }
        }
    }    
    return dp[sz(word1)][sz(word2)];    
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    cout << minDistance("LOVE", "MOVIE");
}
