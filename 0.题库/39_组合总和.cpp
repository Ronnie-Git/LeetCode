/*************************************************************************
	> File Name: 39_组合总和.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Sep 2020 02:04:59 PM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        if (candidates.size() == 0) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> ve;
        dfs(candidates, 0, target, 0, ve, res);
        return res;
    }

    void dfs(vector<int> &arr, int ind, int target, int sum, vector<int> &ve, vector<vector<int> > &res) {
        if (sum == target) {
            res.push_back(ve);
            return ;
        }
        for (int i = ind; i < arr.size(); ++i) {
            if (sum + arr[i] > target) return ;
            ve.push_back(arr[i]);
            dfs(arr, i, target, sum + arr[i], ve, res);
            ve.pop_back();
        }
    }
};
