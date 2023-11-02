class Solution {
private:
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

    bool isValid(int r , int c , int ROW , int COL){
       if(r < 0 || c < 0 || r == ROW || c == COL) return false;
       return true;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return { };
        int ROWS = matrix.size(), COLS = matrix[0].size();

        vector<vector<bool>> pacific_reachable(ROWS, vector<bool>(COLS,false));
        vector<vector<bool>> atlantic_reachable(ROWS, vector<bool>(COLS,false));
        queue<pair<int,int>> q; // the position we will start the bfs from

        //adding the first column to the pacific_reachable
        //and the last column to the atlantic_reachable
        //and adding them both to the queue.

        for(int r = 0 ; r <ROWS ;r++){
            q.push({r,0});
            pacific_reachable[r][0] = true;
            q.push({r,COLS-1});
            atlantic_reachable[r][COLS-1] = true;
        }
        //adding the first row to the pacific_reachable
        //and the last row to the atlantic_reachable
        //and adding them both to the queue.
        for(int c = 0 ; c <COLS ;c++){
            q.push({0,c});
            pacific_reachable[0][c] = true;
            q.push({ROWS-1,c});
            atlantic_reachable[ROWS-1][c] = true;
        }

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;

            for(int i = 0 ; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(!isValid(nr,nc,ROWS,COLS)) 
                    continue;
                if(matrix[nr][nc] >= matrix[r][c]){
                    if(!pacific_reachable[nr][nc] && pacific_reachable[r][c]){
                        pacific_reachable[nr][nc] = true;
                        q.push({nr,nc});
                    }
                    if(!atlantic_reachable[nr][nc] && atlantic_reachable[r][c]){
                        atlantic_reachable[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(int r = 0 ; r < ROWS ; r++){
            for(int c = 0 ; c < COLS ; c++){
                if(pacific_reachable[r][c] && atlantic_reachable[r][c])
                   res.push_back({r,c});
            }
        }
        return res;

        
    }

};
