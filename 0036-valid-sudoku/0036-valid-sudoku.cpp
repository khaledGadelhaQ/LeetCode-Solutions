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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ;  j < 9 ; j++){
                if(board[i][j] == '.') continue;
                char tmp = board[i][j];
                board[i][j] = '.';
                if(!valid(i,j, tmp , board)) return false;
                board[i][j] = tmp;
            }
        }
        return true;
    }
};