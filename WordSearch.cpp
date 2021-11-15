#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<char>>& board, string& word, int r, int c, int pos) {
    if (pos == word.size()) return true;
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[pos]) return false;

    char temp = board[r][c];
    board[r][c] = ' ';

    bool found = check(board, word, r + 1, c, pos + 1)
                    || check(board, word, r - 1, c, pos + 1)
                        || check(board, word, r, c + 1, pos + 1)
                            || check(board, word, r, c - 1, pos + 1);

    board[r][c] = temp;
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.size() * board[0].size() < word.size()) return false; 
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0]) {
                if (check(board, word, i, j, 0) == true) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};

    string target = "cdba";

    cout << exist(board, target);
}