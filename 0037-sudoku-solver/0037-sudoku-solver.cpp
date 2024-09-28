class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                // If the cell is empty, try to fill it
                if (board[row][col] == '.') {
                    // Try digits 1 to 9
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c;  // Place the digit
                            
                            // Recur to try filling the next cells
                            if (solve(board)) return true;
                            
                            board[row][col] = '.';  // Backtrack if solution not found
                        }
                    }
                    return false;  // No valid digit found, need to backtrack
                }
            }
        }
        return true;  // Puzzle solved
    }

    // Check if placing 'c' in board[row][col] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            // Check row
            if (board[row][i] == c) return false;
            // Check column
            if (board[i][col] == c) return false;
            // Check 3x3 sub-grid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};
