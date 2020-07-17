/*************************************************************************
	> File Name: ZJ61_扑克牌中的顺子.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 01:30:01 PM CST
 ************************************************************************/

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int flags[20] = {0}, cnt = 0, j = 15;
        for (int i = 0; i < nums.size(); ++i) {
            ++flags[nums[i]];
            j = ((nums[i] && nums[i] < j) ? nums[i] : j);
        }
        for (int i = j; i < j + 5; ++i) {
            if (!flags[i]) ++cnt;
        }
        return flags[0] >= cnt;
    }
};
