/*************************************************************************
	> File Name: 300_最长上升子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Sep 2020 03:19:11 PM CST
 ************************************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> arr(len + 5);
        int ans = 1;
        arr[ans] = nums[0];
        for (int i = 1; i < len; ++i) {
            if (nums[i] > arr[ans]) {
                arr[++ans] = nums[i];
            } else {
                int l = 0, r = ans, mid;
                while (l < r) {
                    mid = (l + r + 1) >> 1;
                    if (arr[mid] < nums[i]) l = mid;
                    else r = mid - 1;
                }
                arr[l + 1] = nums[i];
            }
        }
        return ans;
    }

};
