int memo[51][51];
const int INF = 1e9;
class Solution {
public:
    int ROW,COL;
    int dp(int r, int c,vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        if(r == ROW-1)
            return grid[r][c];

        auto &ref = memo[r][c];
        if(ref != -1) return ref;

        ref = INF;
        for(int i = 0 ; i < COL ; i++){
            auto ch = grid[r][c] + moveCost[grid[r][c]][i] +  dp(r+1,i,grid,moveCost) ;
            ref = min(ref,ch);
        }
        return ref;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        memset(memo, -1 , sizeof(memo));
        ROW = grid.size();
        COL = grid[0].size();
        int res = INF; 
        for(int i = 0; i < grid[0].size(); i++){
            res = min(res, dp(0,i,grid,moveCost));
        }
        return res;
    }
};