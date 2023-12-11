const int MAX = 100 + 5;
int memo[MAX][MAX];

class Solution {
private:
    vector<vector<int>> memo;
    int ROW,COL;
    int dp(int r, int c, vector<vector<int>>& matrix) {
        if (r == ROW - 1) 
            return matrix[r][c];

        auto &ref = memo[r][c];
        if (ref != INT_MAX) 
            return ref;

        int down = INT_MAX, down_left = INT_MAX, down_right = INT_MAX;
        if (r + 1 < ROW) {
            if (c - 1 >= 0) 
                down_left = dp(r + 1, c - 1, matrix);
            if (c + 1 < COL) 
                down_right = dp(r + 1, c + 1, matrix);
            down = dp(r + 1, c, matrix);
        }

        return ref = min(ref ,  matrix[r][c] + min({down, down_left, down_right}) );
    }
   
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        COL = matrix[0].size();
        memo = vector<vector<int>>(ROW, vector<int>(COL, INT_MAX));
        int res = INT_MAX;
        for(int i = 0 ; i < COL ;i++){
            res = min(res, dp(0,i,matrix));
        }
        return res;
    }
};