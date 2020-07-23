/*************************************************************************
	> File Name: ZJ47_礼物的最大价值.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jul 2020 09:10:54 AM CST
 ************************************************************************/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                if (j == 0) grid[i][j] += grid[i - 1][j];
                else if(i == 0) grid[i][j] += grid[i][j  -1];
                else grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[n - 1][m - 1];
    }
};
