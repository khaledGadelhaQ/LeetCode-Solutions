class Solution {
private:
    int MOD = 1e9 + 7 ;
    int ROW,COL;
    int dr[4] = {1,-1,0,0}; // directional arrays
    int dc[4] = {0,0,1,-1};
    int memo[51][51][51];
    int dp(int r, int c, int maxMove){
        if(r < 0 || c < 0 || r == ROW || c == COL) // out of the boundries = one path  
            return 1;
        if(maxMove == 0) // no more allowed moves = 0 
            return 0 ;
        auto &ref = memo[r][c][maxMove];
        if(ref != -1)
            return ref;
        ref = 0 ;
        for(int d = 0 ; d < 4 ; d++){
            ref += dp(r + dr[d] ,  c + dc[d] , maxMove-1); // go to the four possible directions
            ref %= MOD;
        }
        return ref;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        ROW = m, COL = n;
        memset(memo, -1, sizeof(memo)); // initialize all values to -1
        return dp(startRow,startColumn, maxMove);
    }
};