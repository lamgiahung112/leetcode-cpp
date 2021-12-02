#include <bits/stdc++.h>

using namespace std;

vector<int> d = {1, 7, 30};
map<int, bool> hash;

int dfs(int day, vector<int>& days, vector<int>& costs) {
    if (day == days.size()) {
        return 0;
    }
    if (hash[i]) return hash[i];

    dp[day] = INT_MAX;
    for (int i = 0; i < costs.size(); i++) {
        int j = day;
        // increment j until it reaches an index with a value greater than the current day + 1/7/30
        while (j < days.size() && days[j] < days[day] + d[i])
            j++;
        dp[day] = min(dp[day], costs[i] + dfs(j, days, costs)); 
    }
    return dp[day];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    return dfs(0, days, costs);
}

int main() {

}