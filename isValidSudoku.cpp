#include <bits/stdc++.h>

#define ff first
#define ss second
#define ll long long

#define pb push_back
#define sz(x) int(x.size())

#define forf(i, a, b) for(int i = a; i <= b; ++i)
#define forb(i, b, a) for(int i = b; i >= a; --i)

using namespace std;
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> pli;

const int MOD = 1000000007;

bool isValidSudoku(vector<vector<char>>& board) {
    forf(i, 0, 8) {
        set<int> s;
        int count = 0;
        forf(j, 0, 8) {
            if (board[i][j] != '.') {
                s.insert(board[i][j]);
                count++;
            }
        }
        if (s.size() != count) return false;
    }

    forf(i, 0, 8) {
        set<int> s;
        int count = 0;
        forf(j, 0, 8) {
            if (board[j][i] != '.') {
                s.insert(board[j][i]);
                count++;
            }
        }
        if (s.size() != count) return false;
    }

    forf(i, 0, 2) {
        forf(j, 0, 2) {
            set<int> s;
            int count = 0;
            forf(x, i*3, i*3 + 2) {
                forf(y, j*3, j*3 + 2) {
                    if (board[x][y] != '.') {
                        count++;
                        s.insert(board[x][y]);
                    }
                }
            }
            if (count != sz(s)) return false;
        }
    }
    return true;
}

int main() {
	// ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen('___codeforces.inp', 'r', stdin);
    // freopen('___codeforces.out', 'w', stdout);

    vector<vector<char>> board = 
    {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };

    cout << isValidSudoku(board);
}
