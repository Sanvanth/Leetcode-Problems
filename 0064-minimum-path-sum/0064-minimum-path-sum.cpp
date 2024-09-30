#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Modify the grid in place to store the minimum path sums

        // First, update the first row (can only move right)
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j-1];
        }

        // Update the first column (can only move down)
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i-1][0];
        }

        // Now, fill in the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        // The bottom-right corner will contain the result
        return grid[m-1][n-1];
    }
};
