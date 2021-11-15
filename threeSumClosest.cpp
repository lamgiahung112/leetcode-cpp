#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int minDiff = INT_MAX;
    int ans;
    for (int i = 0; i < nums.size() - 2; i++) {
        int current = nums[i];

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int total = current + nums[left] + nums[right];

            if (total == target) return total;
            else if (total < target) left++;
            else right--;

            if (abs(total - target) < minDiff) {
                minDiff = abs(total - target);
                ans = total;
            }
        }
    }        
    return ans;
}

int main() {
    vector<int> test = {0,2,1,-3}
}