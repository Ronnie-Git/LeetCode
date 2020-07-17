/*************************************************************************
	> File Name: ZJ62_圆圈中最后剩下的数字.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 02:04:15 PM CST
 ************************************************************************/

class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = (res + m) % i;
        }
        return res;
    }
};
