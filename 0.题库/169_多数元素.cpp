/*************************************************************************
	> File Name: 169_多数元素.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Sep 2020 06:10:24 PM CST
 ************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) {
                x = nums[i];
                cnt = 1;
            } else if (x != nums[i]) {
                cnt--;
            } else if (x == nums[i]) {
                cnt++;
            }
        }
        return x;
    }
};
