#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
    string tmp = "";
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        //first word or constructing a word
        if (s[i] != ' ') {
            tmp += s[i];
        }
        // new word
        else if (tmp.size()) {
            v.push_back(tmp);
            tmp = "";
        }
    } 
    for (int i = v.size() - 1; i >= 0; i--) {
        if (tmp.size()) tmp += " ";
        tmp += v[i];
    }
    return tmp;
}

int main() {
    cout << reverseWords("    the   sky   is blue   ");
}