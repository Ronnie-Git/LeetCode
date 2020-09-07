/*************************************************************************
	> File Name: 547_朋友圈.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Sep 2020 03:45:26 PM CST
 ************************************************************************/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() == 0) return 0;
        int n = M.size();
        vector<int> f(n + 5);
        vector<int> vis(n + 5);
        for (int i = 0; i <= n; ++i) f[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) merge(i, j, f);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[find(f[i], f)] == 0) {
                vis[f[i]] = 1;
                ans++;
            } 
        }

        return ans;
    }

    int find(int x, vector<int> &f) {
        return (x == f[x] ? x : (f[x] = find(f[x], f)));
    }

    void merge(int a, int b, vector<int> &f) {
        int fa = find(a, f), fb = find(b, f);
        if (fa > fb) swap(fa, fb);
        f[fb] = fa;
        return ;
    }
};
