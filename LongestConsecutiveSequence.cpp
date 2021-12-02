#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> pq (nums.begin(), nums.end());
    int l = 1;
    int currlen = 0;
    int prev = INT_MIN;
    
    while (pq.size()) {
        int curr = pq.top();
        pq.pop();
        
        if (curr == prev + 1) {
            currlen++;
            l = max(l, currlen);
        }
        else {
            currlen = 1;
        }
        prev = curr;
    }
    return max(l, currlen);
}

int main() {
    vector<int> test = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(test);
}