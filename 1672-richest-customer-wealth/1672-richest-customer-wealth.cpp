class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum {0} ;
        int res {0} ;
        int row = accounts.size() ;
        int col = accounts[0].size();
        for(int i = 0 ; i < row ; i++ ){

            for(int j = 0 ; j < col ; j++ ){
                sum += accounts[i][j];
            }
            res = max(res,sum);
            sum = 0 ;
        }
        return res;
    }
};