class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        sort(nums.begin(),nums.end());
        
        int res {INT_MAX};
        int i = k-1 , j = 0 , sz = nums.size();
        while(i<sz){
          res = min(res, nums[i++] - nums[j++]);
        }
        return res;
        
    }
};