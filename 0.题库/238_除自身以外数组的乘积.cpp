/*************************************************************************
	> File Name: 238_除自身以外数组的乘积.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Sep 2020 04:16:33 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> mul(nums.size() + 5);
        vector<int> res(nums.size());
        int n = nums.size();
        mul[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
           mul[i] = nums[i] * mul[i + 1]; 
        }

        int temp = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = temp * mul[i + 1];
            temp *= nums[i];
        }
        return res;
    }
};
