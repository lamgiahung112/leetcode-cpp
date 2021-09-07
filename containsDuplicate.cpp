#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> isDuplicate;

    for(int i = 0; i < nums.size(); i++) {
        if (isDuplicate[nums[i]]) return true;
        else {
            isDuplicate[nums[i]] = true;
        }
    }
    return false;
}