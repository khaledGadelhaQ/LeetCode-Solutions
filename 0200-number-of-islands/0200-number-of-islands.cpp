  const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    void dfs(int r , int c ,vector<vector<char>>& grid){
        if(r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] == '0') return;
        grid[r][c] = '0';
        for(int d = 0 ; d < 4 ;d++){
            int nr = r + dr[d] , nc = c + dc[d];
            dfs(nr,nc,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size(), COL = grid[0].size();
        int res = 0;
        for(int r = 0 ; r < ROW ; r++){
            for(int c = 0 ; c < COL ; c++){
                if(grid[r][c] == '1'){
                    dfs(r,c,grid); res++;
                }
            }
        }
        return res;
    }
};