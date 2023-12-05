const int MAX = 10000+1;
int memo[MAX];
int dp(int n){
    if(n <= 0)
        return 0;
    if(memo[n] != -1)
        return memo[n];
    int res = INT_MAX;
    for(int i = 1 ; i*i <= n ; i++)
        res = min(res,1 + dp(n - i*i)); 
    return memo[n] = res;
}
class Solution {
public:
    int numSquares(int n) {
        memset(memo,-1,sizeof(memo));
        return dp(n);
    }
};