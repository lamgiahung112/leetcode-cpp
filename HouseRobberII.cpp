#include <bits/stdc++.h>

using namespace std;

int _rob(vector<int>& nums, int pos, int end) {
    int rob1 = nums[pos];
    int rob2 = rob1;

    for (int i = pos + 2; i <= end; i++) {
        int tmp = max(rob1 + n, rob2);
        rob1 = rob2;
        rob2 = tmp;
    }
    return rob1;
}
int rob(vector<int>& nums) {
    return max(_rob(nums, 0, nums.size() - 2), _rob(nums, 1, nums.size() - 1));
}

int main() {
    vector<int> test = {6,6,4,8,4,3,3,10};
    cout << rob(test);
}