#include <bits/stdc++.h>

using namespace std;

map<string, bool> hash;

void dfs(vector<vector<char>>& grid, int row, int col) {
    string key = to_string(row) + "." + to_string(col);
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || hash[key] || grid[row][col] == 0) return;

    hash[key] = true;

    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}

void bfs(vector<vector<char>>& grid, int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});

    while (q.size()) {
        pair<int, int> tmp = q.pop();
        int r = tmp.first, c = tmp.second;
        string key = to_string(r) + "." + to_string(c);
        if (r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || hash[key] || grid[r][c] == '0') continue;

        hash[key] = true;
        q.push({r+1, c});
        q.push({r-1, c});
        q.push({r, c+1});
        q.push({r, c-1});
    }
}

int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            string key = to_string(i) + "." + to_string(j);
            if (!hash[key] && grid[i][j] == '1') {
                ans++;
                bfs(grid, i, j);
            }
        }
    }
    return ans;
}