const int MAX = 500 + 5;
int memo[MAX];
int sz;
int dp(int indx, vector<int>& arr){
    if(indx >= arr.size())
        return 0;
    auto &ref = memo[indx];
    if(ref != -1)
        return ref;
    int mx_ele = 0, sum = 0 ;
    for(int i = indx ; i < sz + indx && i < arr.size() ; i++){
        mx_ele = max(mx_ele, arr[i]);
        sum = mx_ele * (i-indx + 1) ;
        ref  = max(ref , sum + dp( i + 1 , arr));
    }
    return ref;
}
class Solution {
public:
    int maxSumAfterPartitioning(vector<int> arr, int k) {
        memset(memo, -1, sizeof(memo));
        sz = k ;
        return dp(0, arr);
    }
};