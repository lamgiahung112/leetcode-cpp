#include <bits/stdc++.h>

using namespace std;

vector<string> ans;

void generate(string& s, int pos, vector<char> current, int pointsLeft, int len) {
    if (pos == s.size()) {
        if (pointsLeft != 0) return;
        if (len > 3) return;
        if (s[pos - 1] == '.') return;
        if (len == 3) {
            int num = (s[pos - 3] - '0') * 100 + (s[pos - 2] - '0') * 10 + (s[pos - 1] - '0');
            if (num > 255 || num < 100) return;
        }
        
        string v = "";
        for (auto c : current) v += c;
        ans.push_back(v);
    }
    else {
        if (len == 0 || pos == 0) {
            current.push_back(s[pos]);
            generate(s, pos + 1, current, pointsLeft, len + 1);
            current.pop_back();
        }
        if (len == 1 || len == 2) {
            current.push_back('.');
            generate(s, pos, current, pointsLeft - 1, 0);
            current.pop_back();

            current.push_back(s[pos]);
            generate(s, pos + 1, current, pointsLeft, len + 1);
            current.pop_back();
        }
        if (len == 3) {
            int num = (s[pos - 2] - '0') * 100 + (s[pos - 1] - '0') * 10 + (s[pos] - '0');
            if (num > 255 || nums < 100) return;

            current.push_back('.');
            generate(s, pos, current, pointsLeft, 0);     
            current.pop_back();       
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    generate(s, 0, {}, 4, 0);
    return ans;
}

int main() {

}