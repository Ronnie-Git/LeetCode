/*************************************************************************
	> File Name: 96_不同的二叉搜索树.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Aug 2020 09:24:44 PM CST
 ************************************************************************/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 5, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
