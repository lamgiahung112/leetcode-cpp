#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    if (n == 0) return {-1, -1};
    if (abs(nums[0] - target) < abs(nums[n - 1] - target)) {
        int i = 0;

        while (nums[i] <= target && i < n) {
            if (nums[i] == target) {
                ans.push_back(i);
                i++;
                while (i < n && nums[i] == target) {
                    i++;
                }
                ans.push_back(i-1);
                return ans;
            }
            i++;
        }
    }
    else {
        int i = n - 1;

        while (i >= 0 && nums[i] >= target) {
            if (nums[i] == target) {
                int last = i;
                i--;
                while (i >= 0 && nums[i] == target) {
                    i--;
                }
                ans.push_back(i + 1);
                ans.push_back(last);
                return ans;
            }
            i--;
        }
    }
    return ans;
}

int main() {

}