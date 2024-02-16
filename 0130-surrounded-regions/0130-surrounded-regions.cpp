class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,-1,1};
    void solve(vector<vector<char>>& board) {
        int ROW = board.size(), COL = board[0].size();
        queue<pair<int,int>> q;
        
        // Mark boundary 'O's as visited and enqueue them
        for(int i = 0 ; i < ROW ; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'V'; // Marked as visited
                q.push({i,0});
            }
            if(board[i][COL-1] == 'O'){
                board[i][COL-1] = 'V'; // Marked as visited
                q.push({i,COL-1});
            }
        }
        for(int i = 1 ; i < COL-1 ; i++){
            if(board[0][i] == 'O'){
                board[0][i] = 'V'; // Marked as visited
                q.push({0,i});
            }
            if(board[ROW-1][i] == 'O'){
                board[ROW-1][i] = 'V'; // Marked as visited
                q.push({ROW-1,i});
            }
        }
        
        // BFS from boundary 'O's
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int r = top.first, c = top.second;
            for(int d = 0 ; d < 4 ; d++){
                int nr = r + dr[d], nc = c + dc[d];
                if(nr >= 0 && nc >= 0 && nr < ROW && nc < COL && board[nr][nc] == 'O'){
                    board[nr][nc] = 'V'; // Marked as visited
                    q.push({nr,nc});
                }
            }
        }
        
        // Mark remaining 'O's as 'X'
        for(int i = 0 ; i < ROW ; i++){
            for(int j = 0 ; j < COL ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'V'){ // Restore marked 'V's back to 'O'
                    board[i][j] = 'O';
                }
            }
        }
    }
};
