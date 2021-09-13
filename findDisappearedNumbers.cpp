#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int size = nums.size();
    
    vector<int> ans, vec(size + 1, 0);
    
    for (int i = 0; i < size; i++) {
        vec[nums[i]]++;
    }
    
    for (int i = 1; i < size + 1; i++) {
        if (vec[i] == 0) ans.push_back(i);
    }
    
    return ans;
}

int main() {
    vector<int> test = {4,3,2,7,8,2,3,1};
    vector<int> x = findDisappearedNumbers(test);
}