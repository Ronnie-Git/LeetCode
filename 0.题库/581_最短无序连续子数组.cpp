/*************************************************************************
	> File Name: 581_最短无序连续子数组.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Sep 2020 04:38:36 PM CST
 ************************************************************************/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[l] == temp[l]) ++l;
        while (l < r && nums[r] == temp[r]) --r;
        return r == l ? 0 : r - l + 1;
    }
};
