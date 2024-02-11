class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int res = 0;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] != nums[i-1])
                res += i;
        }
        return res;
    }
};