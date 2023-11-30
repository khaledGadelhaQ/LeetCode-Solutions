const int MAX = 100 + 1;
int memo[MAX];

int dp(int start, int end, vector<int>& nums) {

    if (start >= end)
        return 0;

    auto &ret = memo[start];

    if (ret != -1)
        return ret;
    // Pick the first house and skip the adjacent house
    int choice1 = nums[start] + dp(start + 2, end, nums); 
    int choice2 = dp(start + 1, end, nums); // Skip the first house

    return ret = max(choice1, choice2);
}

class Solution {
public:
    int rob(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        int robFirstSkipLast = dp(0, n - 1, nums); // Rob first, skip last
        memset(memo, -1, sizeof(memo));
        int skipFirstRobLast = dp(1, n , nums); // Skip first, rob last

        return max(robFirstSkipLast, skipFirstRobLast);
    }
};
