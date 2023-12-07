class Solution {
public:
    int dp(int amount, vector<int>& coins, vector<int>& memo) {
        if (amount < 0) return -1; // If amount becomes negative, return -1 to signify impossibility
        if (amount == 0) return 0; // Base case: If amount is 0, return 0
        
        if (memo[amount] != 0) return memo[amount]; // If already calculated, return stored value
        
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); ++i) {
            int subproblem = dp(amount - coins[i], coins, memo);
            if (subproblem >= 0) { // Check for valid subproblem result
                res = min(res, subproblem + 1);
            }
        }
        
        memo[amount] = (res == INT_MAX) ? -1 : res; // Store result in memo array
        
        return memo[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, 0); // Initialize memoization array with 0s
        return dp(amount, coins, memo);
    }
};
