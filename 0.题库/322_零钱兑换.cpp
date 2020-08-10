/*************************************************************************
	> File Name: 322_零钱兑换.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Aug 2020 09:33:02 AM CST
 ************************************************************************/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
        return dp[amount] >= 0x3f3f3f3f ? -1 : dp[amount];
    }
};
