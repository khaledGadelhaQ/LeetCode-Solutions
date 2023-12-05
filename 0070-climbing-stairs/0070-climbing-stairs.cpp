const int MAX  = 1000+1;
int memo[MAX];
int n;
int dp(int i){
    if( i >= n)
        return 1;
    auto &ret = memo[i];
    if(ret != -1)
        return ret;
    return ret = dp(i+1) + dp(i+2);
}
class Solution {
public:
    int climbStairs(int n_) {
        n = n_;
        memset(memo, -1,sizeof(memo));
        return dp(1);
    }
};