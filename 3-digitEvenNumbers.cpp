#include <bits/stdc++.h>

using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> s;
    for (int i = 0; i < digits.size(); i++) {
        for (int j = 0; j < digits.size(); j++) {
            for (int k = 0; k < digits.size(); k++) {
                if (i == k || i == j || j == k) continue;
                if (digits[i] != 0 && digits[k] % 2 == 0) {
                    s.insert(digits[i]*100+digits[j]*10+digits[k]);
                }
            }
        }
    }
    vector<int> ans;
    for (auto item : s) {
        ans.push_back(item);
    }
    return ans;
}