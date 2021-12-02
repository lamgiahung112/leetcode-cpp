#include <bits/stdc++.h>

using namespace std;

// Dijkstra shortest path

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adjList (n + 1);
    set<int> s;
    int t = 0;
    // t[0]: source node
    // t[1]: target node
    // t[2]: time to travel
    for (auto t : times) {
        adjList[t[0]].push_back({t[1], t[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while (pq.size()) {
        auto curr = pq.top();
        auto w1 = curr.first, n1 = curr.second;
        pq.pop();
        
        if (s.find(n1) != s.end()) continue;
        s.insert(n1);
        t = max(t, w1);

        for (auto nei : adjList[n1]) {
            pq.push({nei.second + w1, nei.first});
        }
    }

    return s.size() == adjList.size() - 1 ? t : -1;
}

int main() {
    vector<vector<int>> test = {{2, 1, 1}, {2,3,1}, {3,4,1}};
    cout << networkDelayTime(test, 4, 2);
}