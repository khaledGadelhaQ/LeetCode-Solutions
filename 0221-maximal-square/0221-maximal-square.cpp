class Solution {
private:
    int memo[305][305];
    int dp(int r, int c, vector<vector<char>>& matrix){
        if(r < 0 || c < 0 || matrix[r][c] == '0') // out of the boundries, or zero   
            return 0;

        auto &ref = memo[r][c];
        if(ref != -1)
            return ref;

        int up = dp(r-1,c,matrix);
        int left = dp(r,c-1,matrix);
        int diagonal = dp(r-1,c-1,matrix);
        return ref = 1 + min({up,left,diagonal}); // return the maximum valued side of the square
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ROW = matrix.size(), COL = matrix[0].size();
        memset(memo, -1, sizeof(memo));
        int res = INT_MIN;
        for( int r = 0 ; r < ROW ; r++){
            for(int c  = 0 ; c < COL ; c++){
                res = max(res, dp(r,c,matrix));
            }
        }
        return res * res;
    }
};