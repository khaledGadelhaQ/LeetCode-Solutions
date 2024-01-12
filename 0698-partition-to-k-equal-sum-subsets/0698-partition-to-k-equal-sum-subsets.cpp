class Solution {
public:
    bool dp(int partition_idx, int nums_idx, int cur_sum, vector<int>& nums, vector<bool>&picked, int target){
        if(partition_idx == 1) 
            return true;
        if(cur_sum == target) 
            return dp(partition_idx - 1,0,0, nums,picked, target);
        if(nums_idx == nums.size()) 
            return false;

        for(int i = nums_idx; i < (int) nums.size(); i++) {
            if (!picked[i] && cur_sum + nums[i] <= target) {
                picked[i] = true;
                if (dp(partition_idx, i + 1, cur_sum + nums[i], nums, picked, target))
                    return true;	// take it
                picked[i] = false;
                if(cur_sum == 0) break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(k > nums.size() || sum % k != 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> picked (nums.size(), false);
        return dp(k,0,0, nums, picked, sum/k);

    }
};