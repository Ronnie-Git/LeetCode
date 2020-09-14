/*************************************************************************
	> File Name: 461_汉明距离.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Sep 2020 07:32:19 PM CST
 ************************************************************************/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, res = 0;
        while (z) {
            res += 1;
            z = z & (z - 1);
        }
        return res;
    }
};
