/*************************************************************************
	> File Name: 52_N皇后II.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Sep 2020 04:04:57 PM CST
 ************************************************************************/

class Solution {
public:
    int totalNQueens(int n) {
        size = n;
        ans = 0;
        dfs(0);
        return ans;
    }

    void dfs(int ind) {
        if (ind == size) {
            ans += 1;
            return ;
        }
        for (int i = 0; i < size; ++i) {
            if (!check(ind, i)) continue;
            vis.push_back(i);
            dfs(ind + 1);
            vis.pop_back();
        }
        return ;
    }

    bool check(int x, int y) {
        for (int i = 0; i < vis.size(); ++i) {
            if (vis[i] == y || i + vis[i] == x + y || i - vis[i] == x - y) return false;
        }
        return true;
    }

private:
    vector<int> vis;
    int size;
    int ans;
};
