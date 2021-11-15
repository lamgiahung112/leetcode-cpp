#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    int lastInc = -1;
    int i = 1;

    // find last peek
    for (; i < n; i++) {
        if (nums[i] > nums[i-1]) {
            lastInc = i;
        }
    }

    // the arr is reverse sorted so we asc sort
    if (lastInc == -1) {
        for (i = 0; i < n/2; i++) {
            swap(nums[i], nums[n-i+1]);
        }
        return;
    }

    int idx = lastInc;
    for (i = lastInc; i < n; i++) {
        if (nums[i] > nums[lastInc - 1] && nums[i] < nums[idx]) {
            idx = i;
        }
    }

    swap(nums[lastInc - 1], nums[idx]);

    int left = lastInc;
    int right = n - 1;
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

int main() {

}