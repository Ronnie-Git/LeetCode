/*************************************************************************
	> File Name: ZJ49_丑数.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jul 2020 09:40:36 AM CST
 ************************************************************************/

class Solution {
public:
    int nthUglyNumber(int n) {
        int *dp = new int[n];
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            int tmpa = dp[a] * 2, tmpb = dp[b] * 3, tmpc = dp[c] * 5;
            dp[i] = min(min(tmpa, tmpb), tmpc);
            a += (tmpa == dp[i]);
            b += (tmpb == dp[i]);
            c += (tmpc == dp[i]);
        }
        int ret = dp[n - 1];
        delete[] dp;
        return ret;
    }
};
