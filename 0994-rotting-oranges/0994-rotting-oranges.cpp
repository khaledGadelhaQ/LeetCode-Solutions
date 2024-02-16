class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size(), COL = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0 ; i < ROW; i++){
            for(int j = 0 ; j < COL ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int res = 0 ;
        while(!q.empty()){
            int current_size = q.size(); // Number of oranges in the current minute level
            bool rotten = false; // Flag to track if any fresh orange gets rotten in this minute
            for(int k = 0; k < current_size; k++) {
                auto top = q.front(); q.pop();
                int r = top.first, c = top.second;
                for(int d = 0 ; d < 4 ; d++){
                    int nr = r + dr[d], nc =  c + dc[d] ;
                    if(nr < 0 || nc < 0 || nr >= ROW || nc >= COL || grid[nr][nc] != 1) continue;
                    q.push({nr,nc});
                    grid[nr][nc] = 2;
                    rotten = true;
                    fresh--; // Set to true if any fresh orange gets rotten in this minute
                }
            }
            if(rotten) res++; // Increment minutes only if any fresh orange gets rotten
        }
        if(fresh != 0) return -1;
        return res;
    }
};
