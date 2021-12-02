#include <bits/stdc++.h>

using namespace std;

void markInaccessibles(vector<vector<char>>& board, int i, int j) {
    board[i][j] = 'R';

    if (i > 0 && board[i-1][j] == 'O') markInaccessibles(board, i - 1, j);
    if (j > 0 && board[i][j - 1] == 'O') markInaccessibles(board, i, j - 1);
    if (i < board.size() - 1 && board[i + 1][j] == 'O') markInaccessibles(board, i + 1, j);
    if (j < board[0].size() - 1 && board[i][j + 1] == 'O') markInaccessibles(board, i, j + 1);
}

void solve(vector<vector<char>>& board) {
    int n = board.size() - 1;
    int m = board[0].size() - 1;
    if (board.size() < 3 || board[0].size() < 3) return;

    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] == 'O') {
            markInaccessibles(board, i, 0);
        }
        if (board[i][m] == 'O') {
            markInaccessibles(board, i, m);
        }
    }

    for (int i = 0; i < board[0].size(); i++) {
        if (board[0][i] == 'O') {
            markInaccessibles(board, 0, i);
        }
        if (board[n][i] == 'O') {
            markInaccessibles(board, n, i);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == 'R') board[i][j] = 'O';
        }
    }
}

int main() {
    vector<vector<char>> test = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(test);
}