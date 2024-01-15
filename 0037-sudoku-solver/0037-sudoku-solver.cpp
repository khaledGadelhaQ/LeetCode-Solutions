class Solution {
public:
    bool valid(int r,int c, char val, vector<vector<char>>&board){
        int stRow = (r/3)*3;
        int stCol = (c/3)*3;
        for(int i = 0 ; i < 9 ; i++) if(board[r][i] == val || board[i][c] == val) return false;
        for(int x = 0 ; x < 3 ;x++){
            for(int y = 0 ; y < 3 ; y++){
                if(board[stRow+x][stCol+y] == val) return false;
            }
        }
        return true;
    }
    bool solve(int r, int c , vector<vector<char>> &board){
        if(r == 9) return true;
        if(c == 9) return solve(r+1 , 0 , board);
        if(board[r][c] != '.') return solve(r, c+1,board);

        for(char ch = '1' ; ch <= '9' ; ch++){
            if(valid(r,c,ch,board)){
                board[r][c] = ch;
                if(solve(r,c+1, board)) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};