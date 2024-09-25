class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        
        // Traverse through the list of prices
        for (int i = 1; i < prices.size(); ++i) {
            // If the price increases, add the difference to total profit
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        
        return totalProfit;
    }
};
