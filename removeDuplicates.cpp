#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    auto ip = unique(nums.begin(), nums.end());
    return abs(distance(nums.begin(), ip));
}


int main() {
    //vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums = {1,2};
    cout << removeDuplicates(nums);
}