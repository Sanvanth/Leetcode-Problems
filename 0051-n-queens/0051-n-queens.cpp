class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));  // Initialize an empty board
        vector<int> cols(n, 0);                   // Track columns under attack
        vector<int> diag1(2 * n - 1, 0);          // Track diagonals from top-left to bottom-right
        vector<int> diag2(2 * n - 1, 0);          // Track diagonals from bottom-left to top-right
        backtrack(0, n, board, result, cols, diag1, diag2);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result,
                   vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            result.push_back(board);  // A valid solution is found, store the board
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;  // If the column or either diagonal is under attack, skip
            }

            // Place the queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;

            // Recur to place the next queen
            backtrack(row + 1, n, board, result, cols, diag1, diag2);

            // Backtrack by removing the queen
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
};
