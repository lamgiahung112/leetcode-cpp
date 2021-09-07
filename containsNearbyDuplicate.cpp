#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> map; // <val, index>

    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
            return true;
        }
        else {
            map[nums[i]] = i;
        }
    }
    return false;
}

int main() {
    vector<int> test = {1,2,3,1};
    cout << containsNearbyDuplicate(test, 3);
}