class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        buy, profit = prices[0], 0
        for p in prices[1:]:
            profit = max(p - buy, profit)
            buy = min(p, buy)
        return max(profit, 0)