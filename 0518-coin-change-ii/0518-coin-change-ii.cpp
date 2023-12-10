
int memo[5001][301]; // Changed to 2D array for memoization

class Solution {
private:
    int dp(int index, int amount, vector<int>& coins) {
        if (amount == 0) 
            return 1; // Base case: If amount is 0, return 1 (valid combination found)
        if (amount < 0 || index >= coins.size()) 
            return 0; // If amount becomes negative or no coins are left, return 0
        auto &ref = memo[amount][index];
        if (ref != -1) 
            return ref; // If already calculated, return stored value

        
        int pick = dp(index , amount - coins[index], coins); // Include the coin at the current index
        int leave = dp(index + 1 ,amount, coins); // Exclude the coin at the current index

        return ref = pick + leave;
    }

public:
    int change(int amount, vector<int>& coins) {
        memset(memo, -1, sizeof(memo));
        return dp(0,amount, coins);
    }
};
/*
like the pick or leave pattern but when we pick a value we don't 
increase the index
*/