class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int n = sz/3;
        vector<vector<int>> ans;
        for(int i = 0 ; i < sz; i+=3){
           if(nums[i+2] - nums[i] > k) return {};
           ans.push_back({nums[i], nums[i+1] , nums[i+2]});
        }
        return ans;
    }
};