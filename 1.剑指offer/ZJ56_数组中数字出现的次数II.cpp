/*************************************************************************
	> File Name: ZJ56_数组中数字出现的次数II.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jul 2020 11:26:59 AM CST
 ************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int x : nums) {
            one = one ^ (x & ~two);
            two = two ^ (x & ~one);
        }
        return one;
    }
};
