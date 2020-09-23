/*************************************************************************
	> File Name: 200_岛屿数量.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 06:47:22 PM CST
 ************************************************************************/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                ans += 1;
                dfs(i, j, dir, grid);
            }
        }
        return ans;
    }

    void dfs(int x, int y, int (*dir)[2], vector<vector<char> > &grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if (tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[0].size() || grid[tx][ty] == '0') continue;
            dfs(tx, ty, dir, grid);
        }
        return ;
    }
};
