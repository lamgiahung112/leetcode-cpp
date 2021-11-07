#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &image, int row, int col, int oldColor, int newColor, vector<vector<int>> &visited) {
    if (row < 0 || row >= image.size()) return;
    if (col < 0 || col >= image[0].size()) return;
    if (visited[row][col] == 1) return;
    if (image[row][col] != oldColor) return;

    visited[row][col] = 1;
    image[row][col] = newColor;

    dfs(image, row + 1, col, oldColor, newColor, visited);
    dfs(image, row - 1, col, oldColor, newColor, visited);
    dfs(image, row, col + 1, oldColor, newColor, visited);
    dfs(image, row, col - 1, oldColor, newColor, visited);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size();
    int n = image[0].size();
    const int OLDCOLOR = image[sr][sc];
    vector<vector<int>> visited(m, vector<int>(n, 0));

    dfs(image, sr, sc, OLDCOLOR, newColor, visited);
    return image;
}

int main() {
    vector<vector<int>> image = {{8,4,5,3,2,2,2,6,9,5},
    {3,1,3,7,4,8,9,0,1,6},
    {0,7,1,7,5,2,2,8,6,9},
    {9,1,0,5,8,8,0,5,5,9},
    {3,4,9,5,4,8,0,2,7,5},
    {5,1,1,8,1,6,5,9,7,8},
    {9,7,9,4,5,3,4,1,8,2},
    {5,1,6,3,5,4,8,9,0,8},
    {8,8,6,1,0,8,0,6,9,9},
    {4,1,8,7,3,6,9,6,6,1}};
    vector<vector<int>> test = floodFill(image, 8,0,9);
    cout << "done";
    return 0;
}


