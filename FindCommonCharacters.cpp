#include <bits/stdc++.h>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    vector<int> _hash (26);
    vector<string> ans;
    for (auto c : words[0]) {
        _hash[c - 'a']++;
    }

    for (int i = 1; i < words.size(); i++) {
        vector<int> tmp (26);

        for (auto c : words[i]) {
            tmp[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            _hash[i] = min(_hash[i], tmp[i]);
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < _hash[i]; j++) {
            vector<char> s = {char(i + 'a')};
            ans.push_back(string(s.begin(), s.end()));
        }
    }    
    return ans;
}