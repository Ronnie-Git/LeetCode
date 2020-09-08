/*************************************************************************
	> File Name: 77_组合.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Sep 2020 06:44:17 PM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        if (n <= 0 || k <= 0) return res;
        vector<int> temp;
        dfs(1, n, 0, k, temp, res);
        return res;
    }

    void dfs(int num, int n, int cnt, int k, vector<int> &temp, vector<vector<int> > &res) {
        if (cnt == k) {
            res.push_back(temp);
            return ;
        }
        if (n - num + 1 < k - cnt) return ;
        for (int i = num; i <= n; ++i) {
            temp.push_back(i);
            dfs(i + 1, n, cnt + 1, k, temp, res);
            temp.pop_back();
        }
        return ;
    }
};
