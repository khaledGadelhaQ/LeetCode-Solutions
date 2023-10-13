class Solution {
public:
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};

    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    sum += 4;
                    for (int k = 0; k < 4; k++) {
                        if (i + di[k] >= 0 && i + di[k] < row && j + dj[k] >= 0 && j + dj[k] < col){
                            if (grid[i + di[k]][j + dj[k]] == 1) {
                                sum--;
                            }
                        }
                    }
                }
            }
        }
        return sum;
    }
};
