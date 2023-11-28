const int MAX = 100 + 1;
int memo[MAX];

int dp(int i, vector<int>& nums) {
	if (i >= (int) nums.size())
		return 0;

	auto &ret = memo[i];

	if (ret != -1)
		return ret;

	int choice1 = dp(i + 1, nums);	// Leave
	int choice2 = nums[i] + dp(i + 2, nums); // pick

	return ret = max(choice1, choice2);
}
class Solution {
public:
    int rob(vector<int> nums) {
        memset(memo, -1, sizeof(memo));
        return dp(0,nums);
    }
};