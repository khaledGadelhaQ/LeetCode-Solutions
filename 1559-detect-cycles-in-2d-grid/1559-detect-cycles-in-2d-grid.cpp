class Solution {
private:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    bool cycle;
    bool isValid(int r , int c , int ROWS, int COLS){
        if(r < 0 || r == ROWS ||  c < 0 || c == COLS) return false;
        return true;
    } 

    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited, char x ,int pr  = -1 , int pc = -1){
       if(!isValid(r,c,grid.size(),grid[0].size()) || grid[r][c] != x ) return;
       if(visited[r][c]){
        cycle = true;
        return;
       }
        visited[r][c] = true;
        for(int d = 0 ; d < 4 ; d++){
          int nr  = r +dr[d] , nc =c + dc[d];
          if(nr == pr && nc == pc)continue;
          dfs(nr, nc , grid , visited, x , r , c);
        }
       
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {

       int ROWS = grid.size() ,COLS = grid[0].size();
       vector<vector<bool>> visited(ROWS, vector<bool>(COLS));
        for(int r  = 0  ; r < ROWS ; r++){
            for(int c = 0 ; c < COLS ; c++){
                cycle = false;
                if(!visited[r][c])
                  dfs(r,c,grid,visited,grid[r][c]);
                if(cycle) return true;
            }
          
        }
        return false;
    }
};