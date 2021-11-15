#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int l = 0, r = matrix.size() - 1;

    while (l < n) {
        for (int i = l; i < r - l; i++) {
            int top = l, btm = r;

            int topLeft = matrix[top][l + i];

            matrix[top][l + i] = matrix[btm - i][l];
            matrix[btm - i][l] = matrix[btm][r - i];
            matrix[btm][r - i] = matrix[top + i][r];
            matrix[top + i][r] = topLeft;
        }
        l++;
        r--;
    }
}

int main () {

}