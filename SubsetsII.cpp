#include <bits/stdc++.h>

using namespace std;

set<vector<int>> ans = {};
map<int, bool> check;

void generate(vector<int>& nums, int k, vector<int> v, int prev = INT_MIN) {
    if (k == 0) {
        ans.insert(v);
    }
    else {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= prev && !check[i]) {
                v.push_back(nums[i]);
                check[i] = true;
                generate(nums, k - 1, v, nums[i]);
                check[i] = false;
                v.pop_back();
            }
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    for (int i = 0; i <= nums.size(); i++) {
        generate(nums, i, {});
    }
    vector<vector<int>> res;

    for (auto item : ans) {
        res.push_back(*item);
    }
}