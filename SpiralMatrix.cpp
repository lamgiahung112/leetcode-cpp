#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int l = 0, r = matrix[0].size() - 1;
    int top = 0, btm = matrix.size() - 1;

    while (l <= r && top <= btm) {            
        // ====>
        for (int i = l; i <= r; i++) {
            ans.push_back(matrix[top][i]);
        }
        //  ||
        //  ||
        //  \/
        for (int i = top + 1; i <= btm; i++) {
            ans.push_back(matrix[i][r]);
        }

        // <====
        for (int i = r - 1; i > l; i--) {
            ans.push_back(matrix[btm][i]);
        }
        //  /\
        //  ||
        //  ||

        for (int i = btm; i > top && l != r; i--) {
            ans.push_back(matrix[i][l]);
        }
        l++;
        r--;
        top++;
        btm--;
    }
    return ans;
}

int main() {
    vector<vector<int>> test = {{3}, {2}};
    spiralOrder(test);
}