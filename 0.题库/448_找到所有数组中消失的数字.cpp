/*************************************************************************
	> File Name: 448_找到所有数组中消失的数字.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 06 Sep 2020 05:39:39 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};
