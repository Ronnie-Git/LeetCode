/*************************************************************************
	> File Name: 628_三个数的最大乘积.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Sep 2020 03:55:59 PM CST
 ************************************************************************/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] < 0) {
            return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
        }
        return nums[n - 1] * nums[n - 2] * nums[n - 3];
    }
};
