#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int l = 0, r = n - 1;
    int top = 0, btm = n - 1;
    int c = 1;
    vector<vector<int>> matrix (n, vector<int> (n));
    while (l <= r) {
        int i;

        for (i = l; i <= r; i++) {
            matrix[top][i] = c;
            c++;
        }

        for (i = top + 1; i < btm; i++) {
            matrix[i][r] = c;
            c++;
        }

        for (i = r; i > l; i--) {
            matrix[btm][i] = c;
            c++;
        }

        for (i = btm; i > top; i--) {
            matrix[i][l] = c;
            c++;
        }

        l++;
        r--;
        top++;
        btm--;
    }
    return matrix;
}

int main() {

}