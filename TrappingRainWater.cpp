#include <bits/stdc++.h>

using namespace std;

//O(n) time and space
// int trap(vector<int>& height) {
//     vector<int> maxLeft (height.size(), 0);
//     vector<int> maxRight (height.size(), 0);
//     vector<int> mins (height.size());

//     int i, ans = 0;
//     for (i = 1; i < height.size(); i++) {
//         maxLeft[i] = max(maxLeft[i-1], height[i-1]);
//     }

//     for (i = height.size() - 2; i >= 0; i--) {
//         maxRight[i] = max(maxRight[i+1], height[i+1]);
//     }

//     for (i = 0; i < height.size(); i++) {
//         mins[i] = min(maxLeft[i], maxRight[i]);
//     }

//     for (i = 0; i < height.size(); i++) {
//         if (mins[i] - height[i] > 0) {
//             ans += mins[i] - height[i];
//         }
//     }
//     return ans;
// }

//O(n) time and O(1) space

int trap(vector<int>& heights) {
    if (!heights.size()) return 0;
    int left = 0, right = sizeof(heights) - 1;
    int maxL = heights[l], maxR = heights[r];
    int ans = 0;
    
    while (left < right) {
        if (maxL <= maxR) {
            left++;
            maxL = max(maxL, heights[left]);

            if (maxL - heights[left] > 0) {
                ans += maxL - heights[left];
            }
        }

        else {
            right--;
            maxR = max(maxR, heights[right]);

            if (maxR - heights[right] > 0) {
                ans += maxR - heights[right];
            }
        }
    }
    return ans;
}

int main() {

}