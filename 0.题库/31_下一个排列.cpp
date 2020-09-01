/*************************************************************************
	> File Name: 31_下一个排列.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Aug 2020 04:38:24 PM CST
 ************************************************************************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return ;
        int i = nums.size() - 1, j = nums.size() - 1;

        while (i > 0 && nums[i] <= nums[i - 1]) --i;
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return ;
        }

        while (j >= i && nums[j] <= nums[i - 1]) --j;
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
        return ;
    }
};
