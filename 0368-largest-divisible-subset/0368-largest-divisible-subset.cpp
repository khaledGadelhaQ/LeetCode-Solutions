using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sz = nums.size();
        vector<int> dp(sz, 1);
        vector<int> parent(sz, -1);
        int maxSubsetSize = 1;
        int maxSubsetIndex = 0;

        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > maxSubsetSize) {
                        maxSubsetSize = dp[i];
                        maxSubsetIndex = i;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = maxSubsetIndex; i >= 0; i = parent[i]) {
            result.push_back(nums[i]);
        }

        return result;
    }
};
