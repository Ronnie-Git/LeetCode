/*************************************************************************
	> File Name: 136_只出现一次的数字.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Aug 2020 09:26:52 PM CST
 ************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = nums[0];
        for (int i = 1; i < nums.size(); ++i) x ^= nums[i];
        return x;
    }
};
