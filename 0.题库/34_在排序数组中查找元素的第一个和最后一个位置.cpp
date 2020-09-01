/*************************************************************************
	> File Name: 34_在排序数组中查找元素的第一个和最后一个位置.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Aug 2020 05:02:21 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() == 0) return vector<int> (2, -1);
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l == r) return vector<int> (2, -1);
        res.push_back(l);
        res.push_back(r - 1);
        return res;
    }
};
