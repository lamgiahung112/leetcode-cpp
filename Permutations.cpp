#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

map<int, bool> mp;

vector<vector<int>> permute(vector<int>& nums, int n = 0, vector<int> curr = {}) {
    if (n == nums.size()) {
        ans.push_back(curr);
    }
    else {
        for (int i = 0; i < nums.size(); i++) {
            if (!mp[nums[i]]) {
                mp[nums[i]] = true;
                curr.push_back(nums[i]);
                permute(nums, n + 1, curr);
                mp[nums[i]] = false;
                curr.pop_back();
            }
        }
    }
    return ans;
}

int main() {

}