#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    while (k - size > 0) {
        k -= size;
    }
    
    vector<int> overExtended;
    
    for(int i = size - 1; i >= 0; i--) {
        if (i >= size - k) overExtended.push_back(nums[i]);
        else {
            nums[i + k] = nums[i];
        }
    }
    
    for (int i = 0; i < k; i++) {
        nums[i] = overExtended.back();
        overExtended.pop_back();
    }
}

int main() {
    vector<int> test = {1,2};
    rotate(test, 3);
}