const int MAX = 58+1 ;
int memo[MAX]; 

int dp(int n){
    if(n == 1)
        return 1;
    auto &ret = memo[n];
    if(ret != -1)
        return ret;
    ret = n ;
    for(int i = 1 ; i < n ; i++)
        ret = max(ret, i*dp(n-i));
    return ret;
}

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2 || n == 3)
            return n-1;
        memset(memo, -1, sizeof(memo));
        return dp(n);
    }
}; 