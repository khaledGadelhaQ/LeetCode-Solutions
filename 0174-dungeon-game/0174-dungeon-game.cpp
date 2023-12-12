class Solution {
private:
    int memo[205][205];
    int ROW,COL;
    int dp(int r, int c, vector<vector<int>>& matrix){
        if(r == ROW || c == COL) // out of the boundries, or zero   
            return 1e8; // some big value
        auto &ref = memo[r][c];
        if(ref != -1)
            return ref;
        if(r == ROW -1 && c == COL-1){
            // if negitive value we need |value| + 1  which = 1 - (val); 
            // ex: val = -3 so the minHealth will be 1 - (-3) = 4
            if(matrix[r][c] < 0)  
                return 1 - matrix[r][c];
            // if positive value or = 0 we only need 1 health to save the princess
            return 1; 
        }
        // minimum of down and right path
        int minHealth = min(dp(r,c+1,matrix) , dp(r+1,c,matrix));
        // if minHealth required is less than cell is value we return 1
        if(minHealth <= matrix[r][c])
            return ref = 1;
        return ref = minHealth - matrix[r][c];
        
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        ROW = dungeon.size(), COL = dungeon[0].size();
        memset(memo, -1, sizeof(memo));
       return dp(0,0,dungeon);
    }
};