class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(prices[i] - buy, profit);
            buy = min(prices[i], buy);
        }
        return max(profit, 0);
    }
};
