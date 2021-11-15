#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int ans = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        if (area > ans) {
            ans = area;
        }

        if (height[right] > height[left]) {
            left++;
        } else right--;
    }
    return ans;
}

int main() {

}