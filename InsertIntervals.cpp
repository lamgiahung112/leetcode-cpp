#include <bits/stdc++.h>

using namespace std;

bool comp (vector<int> a, vector<int> b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] > b[0]) {
        return false;
    } else {
        return a[1] < b[1];
    }
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), comp);
    vector<int> prev = intervals[0];
    vector<vector<int>> ans;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= prev[1] || intervals[i][0] < prev[0]) {
            prev[1] = max(intervals[i][1], prev[1]);
            prev[0] = min(intervals[i][0], prev[0]);
        } 
        else {
            ans.push_back(prev);
            prev = intervals[i];
        }
    }
    ans.push_back(prev);
    return ans;
}

int main() {

}