/*************************************************************************
	> File Name: 10.11_峰与谷.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Aug 2020 08:27:57 PM CST
 ************************************************************************/

class Solution {
public:
    bool check(int a, int b, int flag) {
        return flag ? (a > b) : (a < b);
    }

    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return ;
        int flag = (nums[0] > nums[1]);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (!check(nums[i], nums[i + 1], flag)) {
                nums[i] ^= nums[i + 1];
                nums[i + 1] ^= nums[i];
                nums[i] ^= nums[i + 1];
            }
            flag ^= 1;
        }
        return ;
    }
};
