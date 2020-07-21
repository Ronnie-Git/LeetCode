/*************************************************************************
	> File Name: ZJ56_数组中数字出现的次数I.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jul 2020 11:27:39 AM CST
 ************************************************************************/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res(2, 0);
        int x = 0, y = 1;
        for (int i = 0; i < nums.size(); ++i) x ^= nums[i];
        while ((y & x) == 0) y <<= 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & y) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        } 
        return res;
    }
};
