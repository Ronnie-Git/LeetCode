/*************************************************************************
	> File Name: 51_N皇后.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Aug 2020 02:54:07 PM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        dfs(0);
        return res;
    }

    void dfs(int ind) {
        if (ind == size) {
            string str(size, '.');
            vector<string> temp(size, str);
            for (int i = 0; i < size; ++i) {
                temp[i][vis[i]] = 'Q';
            }
            res.push_back(temp);
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
    vector<vector<string>> res;
    vector<int> vis;
    int size;
};
