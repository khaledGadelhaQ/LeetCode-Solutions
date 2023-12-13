class Solution {
private:
    bool isSpecial(int r, int c , vector<vector<int>>& mat){
        for(int row = 0 ; row < mat.size() ; row++){
            if(row == r) continue;
            if(mat[row][c] == 1) return false;
        }
        for(int col = 0 ; col < mat[0].size() ; col++){
            if(col == c) continue;
            if(mat[r][col] == 1) return false;
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res {0};
        for(int r = 0 ; r < mat.size() ; r++){
            for(int c = 0 ; c < mat[0].size() ; c++){
                if(mat[r][c] == 1 && isSpecial(r,c,mat))
                    res++;
            }
        }
        return res;
    }
};