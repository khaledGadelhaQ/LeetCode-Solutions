class Solution {
public:
    int ROW,COL;
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    int dfs(int i , int j , vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= ROW || j >= COL || grid[i][j] == 0)
            return 0;
        int res = 1;
        grid[i][j] = 0;
        for(int d = 0 ; d < 4 ; d++){
            res += dfs(i + dr[d] , j + dc[d], grid);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROW = grid.size(), COL = grid[0].size();
        int res = 0;
        for(int i = 0 ; i < ROW ; i++){
            for(int j = 0 ; j < COL ; j++){
                if(grid[i][j] == 1){
                    res = max(res, dfs(i,j,grid));
                }
            }
        }
        return res;
    }
};
/*
start a dfs from every 1 and return the maximum area
*/