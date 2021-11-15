#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int count = 2;

    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[i-2]) {
            count++;
        } else {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return count;
}