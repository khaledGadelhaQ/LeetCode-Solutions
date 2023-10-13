class Solution {
private:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {-1, 1, 0, 0};

    bool is_sub_island;

    bool isValid(int r, int c, int R,int C){
        if(r < 0 || r >= R) return false;
        if(c < 0 || c >= C) return false;
        return true;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int R = grid2.size(), C = grid2[0].size();
        int sum = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid2[i][j] == 0 ) continue;
                is_sub_island = true;
                dfs(i, j,  grid1, grid2);
                sum += is_sub_island;

            }
        }
        return sum;
    }

    void dfs(int r, int c,vector<vector<int>>& grid1 ,vector<vector<int>>& grid2) {
        if(!isValid(r,c,grid1.size(), grid1[0].size()) || grid2[r][c] == 0) return;

        if(grid2[r][c] && !grid1[r][c]){
            is_sub_island = false;
            return;
        }
        grid2[r][c] = 0 ; // visited
        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i] , c + dc[i] , grid1 , grid2);
        }
    }

};

