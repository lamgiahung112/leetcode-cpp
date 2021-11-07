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

string multiplyS(string& num, char& digit, int mult) {
    int carry = 0;
    string ans = "";
    int x = digit - '0';

    if (x == 0) return "0";

    forb(i, sz(num) - 1, 0) {
        int tmp = x * (num[i] - '0') + carry;

        ans.insert(0, to_string(tmp % 10));
        carry = tmp / 10;
    }


    if (carry != 0) {
        ans.insert(0, to_string(carry));
    }
    while (mult != 0) {
        ans += '0';
        mult--;
    }
    return ans;
}

string add(string x, string y) {
    int carry = 0;
    string ans = "";
    int ptr1 = sz(x) - 1;
    int ptr2 = sz(y) - 1;

    while (ptr1 >= 0 && ptr2 >= 0) {
        int dig1 = x[ptr1] - '0';
        int dig2 = y[ptr2] - '0';

        int currSum = dig1 + dig2 + carry;
        ans.insert(0, to_string(currSum % 10));
        carry = currSum / 10;

        ptr1--;
        ptr2--;
    }

    while (ptr1 >= 0) {
        int dig = (x[ptr1] - '0') + carry;
        ans.insert(0, to_string(dig % 10));
        carry = dig / 10;
        ptr1--;
    }

    while(ptr2 >= 0) {
        int dig = (y[ptr2] - '0') + carry;
        ans.insert(0, to_string(dig % 10));
        carry = dig / 10;
        ptr2--;
    }
    if (carry != 0) {
        ans.insert(0, to_string(carry));
    }
    return ans;
}

string multiply(string num1, string num2) {
    if (sz(num1) == 1 && num1[0] == '0') return "0";
    if (sz(num2) == 1 && num2[0] == '0') return "0";

    string ans = "0";
    string num = num1;
    int mult = 0;
    forb(i, sz(num2) - 1, 0) {
        char digit = num2[i];
        string val = multiplyS(num, digit, mult);
        ans = add(ans, val);
        mult++;
    }
    return ans;
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("___codeforces.inp", "r", stdin);
    // freopen("___codeforces.out", "w", stdout);
    string num = "6913259244";
    string digit = "71103343";
    cout << multiply(num, digit);
}
