class Solution {
public:
    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int ROW = img.size();
        int COL = img[0].size();

        vector<vector<int>> ans(ROW, vector<int>(COL, 0));
        for (int r = 0; r < ROW; r++){
            for(int c = 0; c < COL; c++){
                int sum = img[r][c];
                int cnt = 1;
                for(int d = 0; d < 8; d++){
                    int nr = r + dr[d];  // Calculate new row index
                    int nc = c + dc[d];  // Calculate new column index

                    if(nr < 0 || nc < 0 || nr >= img.size() || nc >= img[0].size())
                        continue;

                    sum += img[nr][nc];
                    cnt++;
                }
                ans[r][c] = sum / cnt;
            }
        }
        return ans;
    }
};
