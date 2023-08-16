class Solution {
public:
    int maxProfit(vector<int>& v) {
        int m {0} , r = {0} ;
        for ( int i = 1 ; i < (int) v.size() ; i++ ){

            if(v[i] < v[m]){
                m = i ;
                continue;
            }else{
                r = max(r,v[i]-v[m]);
            }
              
        }
        return r;
    }
};
