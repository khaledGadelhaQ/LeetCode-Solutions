/*
-> we can have only two states [0,1] having a stock or not having one.
-> we can't sell stock if we didn't buy one before.
-> if we sell stock today we can't do anything tommorrow
   so if we sell we should jump to the day after tommorrow.
-> buying is with negitive values and selling with positive values as 
   selling considered to be the profit.
-> So we have three options 
   1.Leave (Do Nothing) 2.Sell  3.Buy.
-> we return the maximum of the 3 values.
*/

/*
Time and space complexity:
Time: O(n)
Space: O(n)
*/
const int MAX = 5000 + 1;
int memo[MAX][2];

int dp(int i, bool has_stock ,vector<int> &nums){
     
    if(i >= nums.size())
      return 0;
    auto &ret = memo[i][has_stock];
    if(ret != -1)
      return ret;
    // we have 3 options buy sell leave
    int ch1 = dp(i+1, has_stock, nums); //leave
    int ch2 = 0, ch3  = 0;

    if(has_stock)
       ch3 = nums[i] + dp(i+2, false, nums); //sell
    else
       ch2 = -nums[i] + dp(i+1, true, nums); //buy

    return ret = max(ch1, max(ch2,ch3));
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        int n = prices.size();   
        if(n<=1)
          return 0;
        int res = dp(0,false,prices) ;
        return res > 0 ? res : 0; 
    }
};

