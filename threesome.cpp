#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) return {};
    int len = nums.size();
    int x = 0;
    set<vector<int>> result;
    //sort
    sort(nums.begin(), nums.end());

    while (x < len - 2) {
        int left = x + 1;
        int right = len - 1;

        while (left < right) {
            if (nums[left] + nums[right] + nums[x] == 0) {
                result.insert({nums[left], nums[right], nums[x]});
                right--;
            }
            if (nums[left] + nums[right] + nums[x] < 0) {
                left++;
            }
            if (nums[left] + nums[right] + nums[x] > 0) {
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

int main() {
    vector<int> test {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(test);
}