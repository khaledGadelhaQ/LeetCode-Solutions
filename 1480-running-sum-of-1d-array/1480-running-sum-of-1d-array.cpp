class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        long sum = nums[0] ;
        for(int i = 1 ; i < nums.size() ; i++){
            nums[i] += sum;
            sum = nums[i] ;
        }
        return nums ;
    }
};