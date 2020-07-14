int maxProfit(int* prices, int pricesSize) {
    int ans = 0, min = prices[0];
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min) min = prices[i];
        if (prices[i] - min > ans) ans = prices[i] - min;
    }
    return ans;
}