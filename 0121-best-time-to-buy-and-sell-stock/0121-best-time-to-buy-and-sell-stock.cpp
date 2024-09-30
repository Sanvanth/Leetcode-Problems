#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Edge case: if there are less than 2 prices, no transaction can be made
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];  // Initialize the minimum price to the first price
        int maxProfit = 0;         // Initialize the maximum profit to 0
        
        // Iterate over the prices
        for (int i = 1; i < prices.size(); ++i) {
            // Update minPrice if a lower price is found
            minPrice = min(minPrice, prices[i]);
            
            // Calculate the current profit and update maxProfit if it's higher
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};
