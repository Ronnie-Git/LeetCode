/*************************************************************************
	> File Name: 79_单词搜索.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Sep 2020 12:22:39 PM CST
 ************************************************************************/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int> > vis(board.size(), vector<int>(board[0].size()));
        int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
        int rlen = board.size(), clen = board[0].size();
        for (int i = 0; i < rlen; ++i) {
            for (int j = 0; j < clen; ++j) {
                if (board[i][j] != word[0]) continue;
                vis[i][j] = 1;
                if (dfs(board, word, dir, vis, i, j, 1)) return true;
                vis[i][j] = 0;
            }
        }

        return false;    
    }
    
    bool dfs(vector<vector<char> > &board, string &word, int dir[][2], vector<vector<int> > &vis, int x, int y, int ind) {
        if (ind == word.size()) return true;
        int rlen = board.size(), clen = board[0].size();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if (tx < 0 || tx >= rlen || ty < 0 || ty >= clen || board[tx][ty] != word[ind] || vis[tx][ty] == 1) continue;
            vis[tx][ty] = 1;
            if (dfs(board, word, dir, vis, tx, ty, ind + 1)) return true;
            vis[tx][ty] = 0;
        }
        return false;
    }
};
