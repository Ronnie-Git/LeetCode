/*************************************************************************
	> File Name: 42_接雨水.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 10 Sep 2020 12:19:49 PM CST
 ************************************************************************/


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int l = 0, r = height.size() - 1, ans = 0;
        int lmax = height[l], rmax = height[r];
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= lmax) lmax = height[l];
                else ans += lmax - height[l];
                l++;
            } else {
                if (height[r] >= rmax) rmax = height[r];
                else ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};
