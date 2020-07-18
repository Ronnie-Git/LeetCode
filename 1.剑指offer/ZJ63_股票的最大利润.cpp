/*************************************************************************
	> File Name: ZJ63_股票的最大利润.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jul 2020 10:12:10 AM CST
 ************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 0) return 0;
        int cost = prices[0], res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res = (res > prices[i] - cost ? res : prices[i] - cost);
            cost = (cost < prices[i] ? cost : prices[i]);
        }
        return res;
    }
};
