class Solution {
public:
	int vis[105][105] = {0};
	int dir[2][2] = {0, 1, 1, 0};
	void dfs(int x, int y, int m, int n, int k, int &ans) {
		for (int i = 0; i < 2; i++) {
			int tx = x + dir[i][0], ty = y + dir[i][1];
			int temp = tx / 10 + tx % 10 + ty / 10 + ty % 10; 
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || temp > k) continue;
			vis[tx][ty] = 1;
            ans += 1;
            dfs(tx, ty, m, n, k, ans);
		}
	}
    int movingCount(int m, int n, int k) {
    	memset(vis, 0, sizeof(vis));
    	int ans = 1;
    	dfs(0, 0, m, n, k, ans);
    	return ans;
    }
};