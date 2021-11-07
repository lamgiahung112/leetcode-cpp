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

string countAndSay(int n) {
    if (n == 1) return "1";
    int it = 0;
    int count = 0;
    string ans = "";
    string s = countAndSay(n - 1);
    char tmp = s[0];
    while (true) 
    {
        if (tmp == s[it]) {
            count++;
        } else {
            // update the ans
            ans += to_string(count);
            ans += tmp;

            tmp = s[it];
            count = 1;
        }
        it++;

        if (it == sz(s)) {
            ans += to_string(count);
            ans += tmp;
            break;
        }
    }
    return ans;
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    cout << countAndSay(4);
}
