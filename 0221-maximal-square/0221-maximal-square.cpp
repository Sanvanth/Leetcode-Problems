class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // DP table to store the max square side length
        int maxSide = 0;

        // Iterate over the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    // If at the top row or left column, the largest square is itself (side length = 1)
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // Update dp[i][j] based on the minimum of the top, left, and top-left neighbors
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]); // Keep track of the largest square
                }
            }
        }

        // Return the area of the largest square
        return maxSide * maxSide;
    }
};
