/*************************************************************************
	> File Name: 152_乘积最大子数组.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 07:20:48 PM CST
 ************************************************************************/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minn = nums[0], maxn = nums[0];
        int ans = nums[0], tmin, tmax;
        for (int i = 1; i < nums.size(); ++i) {
            tmin = minn * nums[i], tmax = maxn * nums[i];
            minn = min(nums[i], min(tmin, tmax));
            maxn = max(nums[i], max(tmin, tmax));
            ans = max(ans, maxn);
        }
        return ans;
    }
};
