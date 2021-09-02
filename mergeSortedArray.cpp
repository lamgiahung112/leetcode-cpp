#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0;
    int j = 0;
    vector<int> clone;
    while(i < m and j < n) {
        if (nums1[i] <= nums2[j]) {
            clone.push_back(nums1[i++]);
        } else {
            clone.push_back(nums2[j++]);
        }
    }

    while(i < m) {
        clone.push_back(nums1[i++]);
    }

    while(j < n) {
        clone.push_back(nums2[j++]);
    }
    nums1 = clone;
}