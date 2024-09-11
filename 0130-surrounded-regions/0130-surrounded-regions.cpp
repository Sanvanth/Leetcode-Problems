class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        // Step 1: Mark 'O's on the boundary and their connected components
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                markSafe(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                markSafe(board, i, n - 1);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                markSafe(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                markSafe(board, m - 1, j);
            }
        }

        // Step 2: Flip all the remaining 'O' to 'X' and all '*' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Surrounded 'O' turns to 'X'
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';  // Restore the marked safe 'O'
                }
            }
        }
    }

private:
    void markSafe(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '*';  // Mark this 'O' as safe

        // Recursively mark all connected 'O's as safe
        markSafe(board, i + 1, j); // Down
        markSafe(board, i - 1, j); // Up
        markSafe(board, i, j + 1); // Right
        markSafe(board, i, j - 1); // Left
    }
};
