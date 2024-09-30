#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting point or the ending point is an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        // DP table to store the number of ways to reach each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the start point
        dp[0][0] = 1;

        // Fill the first column
        for (int i = 1; i < m; ++i) {
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
        }

        // Fill the first row
        for (int j = 1; j < n; ++j) {
            dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        // The bottom-right corner contains the number of unique paths
        return dp[m-1][n-1];
    }
};
