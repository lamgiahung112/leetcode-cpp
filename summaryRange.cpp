#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    if (nums.size() == 0) return {};
    vector<string> ans;

    for (int idx = 0; idx < nums.size();) {
        int start = idx;

        while (idx + 1 < nums.size() && nums[idx] + 1 == nums[idx + 1]) {
            idx++;
        }

        if (idx == start) {
            ans.push_back(to_string(nums[idx]));
            idx++;
        }
        else {
            string key = to_string(nums[start]) + "->" + to_string(nums[idx]);
            idx++;
            ans.push_back(key);
        }
    }    
    return ans;
}