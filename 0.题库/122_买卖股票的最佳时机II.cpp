/*************************************************************************
	> File Name: 122_买卖股票的最佳时机II.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Aug 2020 07:59:48 PM CST
 ************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<vector<int> > dp(prices.size() + 5, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};
