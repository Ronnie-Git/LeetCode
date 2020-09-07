/*************************************************************************
	> File Name: 46_全排列.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Sep 2020 02:11:55 PM CST
 ************************************************************************/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
