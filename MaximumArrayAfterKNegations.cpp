#include <bits/stdc++.h>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<int> negs;
    int sum = 0;
    // get total sum and negative numbers
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) negs.push_back(nums[i]);
        sum += nums[i];
    }

    // if there is at least 1 negative
    // turn the negatives in to positive.
    // if negative >= k we return sum
    if (negs.size()) {
        for (int i = 0; i < negs.size() && k > 0; i++) {
            nums[i] *= -1;
            sum += 2*(-negs[i]);
            k--;
        }
    }
    if (k % 2 == 0) return sum;
    
    // else we just need to negate the smallest num
    sort(nums.begin(), nums.end());
    sum -= 2*nums[0];
    return sum;
}

int main() {

}