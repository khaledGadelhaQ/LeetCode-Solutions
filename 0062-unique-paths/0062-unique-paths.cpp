const int MAX = 101;
int memo[MAX][MAX];
class Solution {
private:
    int ROW,COL;
    int dp(int r , int c){
        if(r == ROW && c == COL)
            return 1;
        if(r > ROW || c > COL)
            return 0;
        auto &ref = memo[r][c];
        if(ref != -1)
            return ref;
        int down = dp(r+1,c);
        int right = dp(r,c+1);

        return ref = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        ROW = m ;
        COL = n;
        memset(memo, -1, sizeof(memo));
        return dp(1,1);
    }
};