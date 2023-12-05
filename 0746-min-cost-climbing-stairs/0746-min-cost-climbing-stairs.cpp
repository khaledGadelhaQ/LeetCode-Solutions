const int MAX  = 1000+1;
int memo[MAX];
int dp(int n, vector<int>& cost){
    if( n >= cost.size())
        return 0 ;
    auto &ret = memo[n];
    if(ret != -1)
        return ret;
    return ret = cost[n]  + min( dp(n+1,cost), dp(n+2,cost) );
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(memo,-1,sizeof(memo));
        return min( dp(0,cost),  dp(1,cost));
    }
};