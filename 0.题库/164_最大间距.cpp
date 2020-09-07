/*************************************************************************
	> File Name: 164_最大间距.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Sep 2020 09:17:36 PM CST
 ************************************************************************/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            res = max(nums[i + 1] - nums[i], res);
        }
        return res;
    }
};
