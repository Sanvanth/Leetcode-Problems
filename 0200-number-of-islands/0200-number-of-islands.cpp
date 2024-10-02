class Solution {
public:
    // Helper function to perform DFS and mark visited land cells
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Boundary check and if the cell is water or already visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';
        
        // Explore the neighboring cells in all 4 directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;
        
        // Iterate over all cells in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we encounter a land cell ('1'), start a DFS
                if (grid[i][j] == '1') {
                    islandCount++;  // We've found a new island
                    dfs(grid, i, j);  // Explore the entire island and mark it
                }
            }
        }
        
        return islandCount;
    }
};
