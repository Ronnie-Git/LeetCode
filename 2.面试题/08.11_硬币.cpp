/*************************************************************************
	> File Name: 08.11_硬币.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Aug 2020 09:33:51 AM CST
 ************************************************************************/

class Solution {
public:
    int waysToChange(int n) {
        const long long mod = 1000000007;
        vector<int> dp(n + 1);
        int coins[4] = {25, 10, 5, 1};
        dp[0] = 1;
        for (int i = 0; i < 4; ++i) {
            for (int j = coins[i]; j <= n; ++j) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
            }
        }
        return dp[n];
    }
};
