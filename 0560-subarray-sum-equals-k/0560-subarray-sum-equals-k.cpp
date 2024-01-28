class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> prefixSum;
        int sum = 0 ;
        prefixSum[sum]++;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            if(prefixSum.count(sum-k)) 
                count += prefixSum[sum-k];
            prefixSum[sum]++;
        }
        return count;
    }
};