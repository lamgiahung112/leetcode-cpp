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

int jump(vector<int>& nums) {
    int minReqJump = 0, mxLenCurJump = 1, mxLenNextJump = 1;
    for (auto i = 0; i < sz(nums) - 1; i++) {
        mxLenCurJump--;
        mxLenNextJump = max(mxLenNextJump, nums[i]);

        if (mxLenCurJump == 0) {
            mxLenCurJump = mxLenNextJump;
            minReqJump++;
        }
    }
    return minReqJump;
}
int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    vector<int> tests = {2,3,1,1,4};
    cout << jump(tests);
}
