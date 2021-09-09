#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int ptr1 = 0;
    int ptr2 = 0;
    vector<int> result;
    while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
        if (nums1[ptr1] == nums2[ptr2]) {
            result.push_back(nums1[ptr1]);
            ptr1++;
            ptr2++;
        }
        else if (nums1[ptr1] < nums2[ptr2]) {
            ptr1++;
        }
        else {
            ptr2++;
        }
    }
    vector<int>::iterator ip;

    // Using std::unique
    ip = std::unique(result.begin(), result.end());

    // Resizing the vector so as to remove the undefined terms
    result.resize(distance(result.begin(), ip));
    return result;
}

int main() {
    vector<int> test1 = {4, 9, 5};
    vector<int> test2 = {9, 4, 9, 8, 4};
    vector<int> test = intersection(test1, test2);
}