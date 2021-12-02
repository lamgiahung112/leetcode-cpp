#include <bits/stdc++.h>

using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    pair<int, int> rook;
    int cnt = 0;

    // get coordinates of chess
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                rook = {i, j};
            }
        }
    }

    for (int i = rook.first - 1; i >= 0; i--) {
        if (board[i][rook.second] == 'p') {
            cnt++;
            break;
        }
        else if (board[i][rook.second] == 'B')
            break;
    }

    for (int i = rook.first + 1; i < 8; i++) {
        if (board[i][rook.second] == 'p') {
            cnt++;
            break;
        }
        else if (board[i][rook.second] == 'B')
            break;
    }

    for (int i = rook.second - 1; i >= 0; i--) {
        if (board[rook.first][i] == 'p') {
            cnt++;
            break;
        }
        else if (board[rook.first][i] == 'B')
            break;
    }

    for (int i = rook.second + 1; i < 8; i++) {
        if (board[rook.first][i] == 'p') {
            cnt++;
            break;
        }
        else if (board[rook.first][i] == 'B')
            break;
    }
}

int main() {

}