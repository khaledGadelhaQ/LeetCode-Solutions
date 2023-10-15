class Solution {
private:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {-1, 1, 0, 0};


    bool isValid(int r, int c, int R,int C){
        if(r < 0 || r >= R) return false;
        if(c < 0 || c >= C) return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited , int color) {
        if (!isValid( r, c, grid.size(), grid[0].size()) || visited[r][c] || grid[r][c] != color) return;

        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
           dfs(nr, nc, grid,visited , color);
        }
    }

    void CheckForBoundries(vector<vector<int>>& grid, vector<vector<bool>>& visited , int newColor ){

        int R = grid.size(), C = grid[0].size();

        for(int i = 0 ; i < R ; i++){

            for(int j = 0 ; j < C ; j++){

                if(!visited[i][j]) continue;

                for( int d = 0 ; d < 4 ; d++){
                   int nr = i + dr[d], nc = j + dc[d];
                   if(!isValid(nr,nc, R , C) || !visited[nr][nc] ){
                     grid[i][j] = newColor;
                     break;
                   }

                }
                
            }
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        if(grid[row][col] == color) return grid;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(row , col , grid , visited ,grid[row][col]);
        CheckForBoundries(grid, visited, color);
        return grid;

    }

};