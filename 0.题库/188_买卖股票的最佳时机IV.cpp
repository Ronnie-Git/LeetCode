class Solution {
public:
    int func(vector<int>& p) {
        int ret = 0;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] > p[i - 1]) ret += p[i] - p[i - 1];
        }
        return ret;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;
        if (k > prices.size() / 2) return func(prices);
        vector<vector<int> > dp;
        for (int i = 0; i < k; i++) {
            vector<int> temp(2);
            temp[0] = -0x3f3f3f3f, temp[1] = 0;
            dp.push_back(temp);
        }
        for (int i = 0; i < prices.size(); i++) {
            dp[0][0] = max(dp[0][0], 0 - prices[i]);
            dp[0][1] = max(dp[0][1], dp[0][0] + prices[i]);
            for (int j = 1; j < k; j++) {
                dp[j][0] = max(dp[j][0], dp[j - 1][1] - prices[i]);
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
            }
        }
        return dp[k - 1][1];
    }
};