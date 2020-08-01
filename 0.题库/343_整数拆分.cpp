/*************************************************************************
	> File Name: 343_整数拆分.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Jul 2020 08:36:48 AM CST
 ************************************************************************/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int a = n / 3, b = n % 3;
        if (b == 1) return (int)pow(3, a - 1) * 4;
        if (b == 0) b = 1;
        return (int)pow(3, a) * b;
    }
};
