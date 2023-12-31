class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int res = -1 ;
        for(int i  = 0 ; i < n ; i++){
            for( int  j = n-1 ; j >= i ; j--){
                if(s[i] == s[j]){
                    res = max(res, j-i-1);
                }
            }
        }
        return res;
    }
};