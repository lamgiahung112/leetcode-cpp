#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans = {};

vector<vector<int>> subsets(vector<int>& nums) {
    for (int i = 0; i <= nums.size(); i++) {
        generate(nums, -1, i, {});
    }
    return ans;
}

void generate(vector<int>& nums, int prev, int k, vector<int> v) {
    if (k == 0) {
        ans.push_back(v);
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > prev && !included[nums[i]]) {
                v.push_back(nums[i]);
                generate(nums, nums[i], k - 1, v);
                v.pop_back();
            }
        }
    }
}

int main() {}