class Solution {
private:
 
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {-1, 1, 0, 0};

    bool boundry;

    bool isValid(int r, int c, int ROWS ,int COLS){
        if(r < 0 || r >= ROWS) return false;
        if(c < 0 || c >= COLS) return false;
        return true;
    }

    bool atBoundries(int r , int c , int ROWS , int COLS){
        if(r == 0 || c == 0 || r  == ROWS-1 || c == COLS-1) return true;
        return false;
    }

    void dfs(int r , int c , vector<vector<int>>& grid){
        // out of boundries
        if(!isValid(r,c,grid.size() , grid[0].size()) || grid[r][c] == 1 ) return ;
        // touches water
        if(atBoundries(r,c,grid.size(),grid[0].size())){
            boundry = true;
        }
        // mark it as visited
        grid[r][c] = 1;
        for(int d = 0 ; d < 4 ; d++){
            dfs(r + dr[d] , c +dc[d] , grid) ;
        }
        
    }

public:
    int closedIsland(vector<vector<int>>& grid) {


        int ROWS = grid.size(), COLS = grid[0].size();
        int numOfClosedIslands {0};
        for(int r = 0 ;  r < ROWS ; r++){

            for(int c = 0 ; c < COLS ; c++){
                if(grid[r][c] == 0){
                    boundry = false;
                    dfs(r,c,grid);
                    numOfClosedIslands += !boundry;
                    
                }
                
            }
        }
        return numOfClosedIslands;

    }
};