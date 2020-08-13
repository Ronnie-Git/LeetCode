/*************************************************************************
	> File Name: 724_寻找数组的中心索引.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Aug 2020 02:03:57 PM CST
 ************************************************************************/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        int presum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (presum == sum - presum - nums[i]) return i;
            presum += nums[i];
        }

        return -1;
    }
};
