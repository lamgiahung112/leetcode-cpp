#include <bits/stdc++.h>

using namespace std;

bool search(vector<int>& nums, int target) {
    if (abs(target - nums[nums.size() - 1]) <= abs(target - nums[0])) {
        int i = nums.size() - 1;

        while (i >= 0) {
            if (nums[i] == target) return true;
            i--;
        }
        return false;
    }
    else {
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == target) return true;
            i++;
        }
        return false;
    }
}

int main() {

}