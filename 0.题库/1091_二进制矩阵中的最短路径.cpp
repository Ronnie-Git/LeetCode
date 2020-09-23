/*************************************************************************
	> File Name: 1091_二进制矩阵中的最短路径.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 07:31:15 PM CST
 ************************************************************************/

int n = 1, m = 1;

struct pos {
    int x;
    int y;
    int dis;

    pos(int _x, int _y, int _dis) : x(_x), y(_y), dis(_dis) {}
};
bool operator< (const pos A, const pos B) {
    return max(n - 1 - A.x, m - 1 - A.y) + A.dis >= (max(n - 1 - B.x, m - 1 - B.y) + B.dis);
}

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() ) return -1; 
        n = grid.size(); m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        if (n == 1 && m == 1) return 1;


        vector<vector<int>> mov {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, 0}, {0, -1}, {-1, -1}};
        vector<bool> vis(n * m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    vis[i * m + j] = true;
                }
            }
        }

        // 不需要记录父节点，故openList只保存最小花费
        vector<int> openList(n * m, 0);
        openList[0] = 1;
        
        priority_queue<pos> q;
        q.push(pos(0, 0, 1));
        while (!q.empty()) {
            pos cur = q.top();
            q.pop();
            int curIdx = cur.x * m + cur.y;
            vis[curIdx] = true;
            for (int k = 0; k < 8; ++k) {
                int xx = cur.x + mov[k][0];
                int yy = cur.y + mov[k][1];
                int nextIdx = xx * m + yy;
                if (0 <= xx && xx < n && 0 <= yy && yy < m && !vis[nextIdx]) {
                    if (xx == n - 1 && yy == m - 1) {
                        return openList[curIdx] + 1;
                    }
                    // 没有到走过改点或者当前的路线更优
                    if (openList[nextIdx] == 0 || openList[nextIdx] > openList[curIdx] + 1) {
                        openList[nextIdx] = openList[curIdx] + 1;
                        pos next(xx, yy, openList[curIdx] + 1);
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
