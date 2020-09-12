/*************************************************************************
	> File Name: 216_组合总和III.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Sep 2020 11:20:40 AM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> temp;
        dfs(1, 0, k, 0, n, temp, res);
        return res;
    }

    void dfs(int ind, int cnt, int k, int sum, int n, vector<int> &temp, vector<vector<int> > &res) {
        if (cnt == k) {
            if (sum == n) res.push_back(temp);
            return ;
        }
        for (int i = ind; i <= 9; ++i) {
            if (i + sum > n) return ;
            temp.push_back(i);
            dfs(i + 1, cnt + 1, k, sum + i, n, temp, res);
            temp.pop_back();
        }
        return ;
    }
};
