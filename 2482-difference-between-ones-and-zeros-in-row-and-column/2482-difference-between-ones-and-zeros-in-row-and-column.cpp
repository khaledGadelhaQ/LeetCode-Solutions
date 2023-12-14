#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> ans(rows, vector<int>(cols, 0)); // Initialize ans with the same size as grid

        vector<int> onesRow(rows, 0);
        vector<int> onesCol(cols, 0);

        // Precompute count of ones for each row and column
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                onesRow[r] += grid[r][c];
                onesCol[c] += grid[r][c];
            }
        }

        for (int r = 0; r < rows; r++) {
            int zerosRow = cols - onesRow[r]; // Calculate zeros in the row

            for (int c = 0; c < cols; c++) {
                int zerosCol = rows - onesCol[c]; // Calculate zeros in the column

                ans[r][c] = onesRow[r] + onesCol[c] - zerosRow - zerosCol; // Compute the difference
            }
        }
        return ans;
    }
};
