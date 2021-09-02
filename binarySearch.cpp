#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target, int start, int end) {
    int mid = (start + end) / 2;
    while (start <= end) {
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            start = mid + 1;
            mid = (start + end) / 2; 
        }
        if (nums[mid] > target) {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    cout << binarySearch(nums, 2, 0, nums.size() - 1);
}


