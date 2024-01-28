class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size(), COL = matrix[0].size();
        for(int i = 0 ; i < ROW ; i++){
            for(int j = 1 ; j < COL ; j++ ){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int  res = 0;
        unordered_map<int,int> counter;
        for(int i = 0 ; i < COL ; i++){
            for(int j = i ; j < COL ; j++){
                counter = {{0,1}};
                int sum = 0;
                for(int r = 0 ; r < ROW ; r++){
                    sum += matrix[r][j] - ( i > 0 ? matrix[r][i-1] : 0);
                    if(counter.count(sum - target))
                        res += counter[sum-target];
                    counter[sum]++;
                }
            }
        }
        return res;
    }
};