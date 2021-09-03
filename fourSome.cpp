#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums, int index, int target) {
    if (nums.size() < 3) return {};
    int len = nums.size();
    int x = index;
    set<vector<int>> result;
    
    while (x < len - 2) {
        int left = x + 1;
        int right = len - 1;

        while (left < right) {
            if (nums[left] + nums[right] + nums[x] == target) {
                result.insert({nums[left], nums[right], nums[x]});
                right--;
            }
            if (nums[left] + nums[right] + nums[x] < target) {
                left++;
            }
            if (nums[left] + nums[right] + nums[x] > target) {
                right--;
            }
        }

        x++;
    }
    
    set<vector<int>>::iterator it = result.begin();
    vector<vector<int>> ans;
    while (it != result.end()) {
        ans.push_back(*it);
        it++;
    }
    return ans;
}

vector<vector<int>> fourSome(vector<int> &nums, int target) {
    if (nums.size() < 4) return {};
    sort(nums.begin(), nums.end());
    set<vector<int>> fourList;
    for (int i = 0; i < nums.size() - 3; i++) {
        vector<vector<int>> subList = threeSum(nums, i + 1, target - nums[i]);
        if (!subList.empty()) {
            for (auto vec: subList) {
                vec.push_back(nums[i]);
                fourList.insert(fourList.begin(), vec);
            }
        }
    }

    set<vector<int>>::iterator it = fourList.begin();
    vector<vector<int>> ans;
    while (it != fourList.end()) {
        ans.push_back(*it);
        it++;
    }
    return ans;
}

int main() {
    vector<int> test = {2,2,2,2,2};
    vector<vector<int>> sss = fourSome(test, 8);
}