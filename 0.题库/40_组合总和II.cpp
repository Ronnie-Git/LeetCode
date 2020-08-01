/*************************************************************************
	> File Name: 40_组合总和II.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Aug 2020 08:27:44 AM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        if (candidates.size() == 0) return res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, temp, res);
        return res;
    }

    void dfs(vector<int> &arr, int target, int ind, int sum, vector<int> &temp, vector<vector<int>> &res) {
        for (int i = ind; i < arr.size(); ++i) {
            if (sum + arr[i] > target) return ;
            if (i > ind && arr[i] == arr[i - 1]) continue;
            temp.emplace_back(arr[i]);
            if (sum + arr[i] == target) {
                res.emplace_back(temp);
                temp.pop_back();
                return ;
            }
            dfs(arr, target, i + 1, sum + arr[i], temp, res);
            temp.pop_back();
        }
        return ;
    }
};
