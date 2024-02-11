const int MAX = 70 + 1;
int memo[MAX][MAX][MAX];
class Solution {
public:
    int d[3] = {0, 1, -1};
    int ROW, COL;
    int dp(int r1, int c1, int c2, vector<vector<int>>& grid){
        if(r1 == ROW) return 0;
        if(c1 < 0 || c1 >= COL || c2 < 0 || c2 >= COL) return 0;
        
        auto &ret = memo[r1][c1][c2];
        if(ret != -1) return ret;
        ret = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                ret = max(ret, dp(r1+1, c1+d[i], c2+d[j], grid));
            }
        }
        ret += (c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r1][c2];
        return ret;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo, -1, sizeof(memo));
        ROW = grid.size();
        COL = grid[0].size();
        return max(0, dp(0, 0, COL-1, grid));
    }
};
