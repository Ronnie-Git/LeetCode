/*************************************************************************
	> File Name: 287_寻找重复数.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Aug 2020 11:23:32 AM CST
 ************************************************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) return nums[i];
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};
