/*************************************************************************
	> File Name: 215_数组中的第K个最大元素.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 07:31:40 PM CST
 ************************************************************************/



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < k; ++i) q.push(nums[i]);
        for (int i = k; i < nums.size(); ++i) {
            q.push(nums[i]);
            q.pop();
        }
        return q.top();
    }
};
