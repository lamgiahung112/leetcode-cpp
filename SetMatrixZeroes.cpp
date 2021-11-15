#include <bits/stdc++.h>

using namespace std;

bool visited [201][201];

void setRow (vector<vector<int>>& matrix, const int r, int c) {
    if (c < 0) return;
    if (c >= matrix[0].size()) return;
    if (visited[r][c]) return;

    visited[r][c] = true;
    matrix[r][c] = 0;

    setRow(matrix, r, c - 1);
    setRow(matrix, r, c + 1);
} 

void setCol (vector<vector<int>>& matrix, int r, const int c) {
    if (r < 0) return;
    if (r >= matrix.size()) return;
    if (visited[r][c]) return;

    visited[r][c] = true;
    matrix[r][c] = 0;

    setCol(matrix, r + 1, c);
    setCol(matrix, r - 1, c);
} 

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> v;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                v.push_back({i, j});
            }
        }
    }
    for (auto p : v) {
        visited[p.first][p.second] = false;
        setRow(matrix, p.first, p.second);
        visited[p.first][p.second] = false;
        setCol(matrix, p.first, p.second);
    }
}

int main() {
    vector<vector<int>> test = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    setZeroes(test);
}