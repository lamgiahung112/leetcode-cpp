#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& preMap, set<int>& visited, int course) {
    if (visited.find(course) != visited.end()) {
        return false;
    }
    if (!preMap[course].size()) return true;

    visited.insert(course);

    for (auto pre : preMap[course]) {
        if (!dfs(preMap, visited, pre)) return false;
    }
    visited.erase(course);
    preMap[course] = {};
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> preMap (numCourses);

    for (auto pair : prerequisites) {
        preMap[pair[0]].push_back(pair[1]);
    }
    set<int> visited;
    for (int i = 0; i < numCourses; i++) {
        if (visited.find(i) != visited.end()) continue;

        if (!dfs(preMap, visited, i)) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> pre = {{1,4},{2,4},{3,1},{3,2}};
    cout << canFinish(5, pre);
}