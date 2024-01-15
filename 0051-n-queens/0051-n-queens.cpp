class Solution {
public:
    vector<vector<bool>> board;
    vector<vector<string>> res;
    vector<string> line;


    bool isSafe(int row, int col, int n) {
        // Check if there is a queen in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col]) {
                return false;
            }
        }

        // Check if there is a queen in the left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j]) {
                return false;
            }
        }

        // Check if there is a queen in the right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j]) {
                return false;
            }
        }

        return true;
    }

    void solve(int row, int n) {
        if (row == n) {
            res.push_back(line);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n)) {
                board[row][col] = true;
                line[row][col] = 'Q';
                solve(row + 1, n);
                line[row][col] = '.';
                board[row][col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<vector<bool>>(n, vector<bool>(n, false));
        string str;
        line = vector<string> (n,string(n,'.'));
        solve(0, n);
        return res;
    }
};
