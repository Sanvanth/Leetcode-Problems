#include <vector>
#include <string>
#include <cstdint> // For uint64_t

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.size();
        int n = t.size();
        
        // Initialize the DP table with uint64_t
        std::vector<std::vector<uint64_t>> dp(m + 1, std::vector<uint64_t>(n + 1, 0));
        
        // An empty t can be matched by any prefix of s in exactly one way
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    // Check for overflow before adding
                    if (dp[i - 1][j - 1] > UINT64_MAX - dp[i - 1][j]) {
                        dp[i][j] = UINT64_MAX; // Cap at max value if overflow is detected
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        // Convert the result to int
        uint64_t result = dp[m][n];
        
        // Ensure the result fits within 32-bit integer range
        if (result > INT_MAX) {
            return INT_MAX;
        }
        return static_cast<int>(result);
    }
};
