#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int solve(vector<int> &nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            nums[i] = -1;
        }
    }
    bubbleSort(nums);
    for(auto item : nums) {
        if (item >= 0) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout << solve(nums, 2);
}