const int MAX_AMOUNT = 1001;
int memo[MAX_AMOUNT];

class Solution {
private:
    int dp(int amount, vector<int>& nums) {
        if (amount == 0)
            return 1;
        
        if (amount < 0)
            return 0;
        
        auto &ref = memo[amount];
        if (ref != -1)
            return ref;
        
        ref = 0;

        for (int i = 0; i < nums.size(); ++i) {
            ref += dp(amount - nums[i], nums);
        }
        
        return ref;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(memo, -1, sizeof(memo));
        return dp(target, nums);
    }
};
