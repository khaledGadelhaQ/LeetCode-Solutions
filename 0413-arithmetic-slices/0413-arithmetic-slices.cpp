class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int res = 0, tmp = 0 ;
        for(int i = 2 ; i < n ; i++ ){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                tmp++;
            else 
                tmp = 0;
            res += tmp;
        }
        return res;
    }
};