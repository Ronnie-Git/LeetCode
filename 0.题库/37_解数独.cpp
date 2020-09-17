/*************************************************************************
	> File Name: 37_解数独.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Sep 2020 04:38:46 PM CST
 ************************************************************************/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
        return ;
    }

    bool dfs(vector<vector<char> > &board, int x) {
        int n = board.size(), m = board[0].size();
        for (int i = x; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != '.') continue;
                for (int num = 1; num <= 9; ++num) {
                    if (!check(i, j, '0' + num, board)) continue;
                    board[i][j] = '0' + num;
                    if (dfs(board, i)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }

    bool check(int x, int y, char ch, vector<vector<char> > &board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[i][y] == ch) return false;
        }
        for (int i = 0; i < m; ++i) {
            if (board[x][i] == ch) return false;
        }

        int xs = x / 3 * 3, ys = y / 3 * 3;
        for (int i = xs; i < xs + 3; ++i) {
            for (int j = ys; j < ys + 3; ++j) {
                if (board[i][j] == ch) return false;
            }
        }

        return true;
    }
};
