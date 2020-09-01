/*************************************************************************
	> File Name: 55_跳跃游戏.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Aug 2020 06:58:38 PM CST
 ************************************************************************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int x = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (x < i) return false;
            if (nums[i] + i > x) x = nums[i] + i;
        }
        return true;
    }
};
