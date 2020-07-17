/*************************************************************************
	> File Name: ZJ59-I.滑动窗口的最大值.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 10:56:16 AM CST
 ************************************************************************/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!maxq.empty() && nums[i] > maxq.back()) maxq.pop_back();
            maxq.push_back(nums[i]);
            if (i >= k && nums[i - k] == maxq.front()) maxq.pop_front();
            if (i >= k - 1) res.push_back(maxq.front());
        }
        return res;
    }
};
