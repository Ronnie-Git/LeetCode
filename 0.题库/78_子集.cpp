/*************************************************************************
	> File Name: 78_子集.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Sep 2020 02:23:36 PM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back(vector<int> ());
        if (nums.size() == 0) return res;
        vector<int> ve;
        dfs(nums, 0, ve, res);
        return res;
    }

    void dfs(vector<int> &nums, int ind, vector<int> &ve, vector<vector<int> > &res) {
        if (ind == nums.size()) return ;

        for (int i = ind; i < nums.size(); ++i) {
            ve.push_back(nums[i]);
            res.push_back(ve);
            dfs(nums, i + 1, ve, res);
            ve.pop_back();
        }

        return ;
    }
};
