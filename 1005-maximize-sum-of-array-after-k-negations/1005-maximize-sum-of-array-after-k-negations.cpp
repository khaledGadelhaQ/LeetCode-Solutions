class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum {0};
        int mn = INT_MAX;
        for(int i = 0 ; i <(int) nums.size() ; i++){
            if(k && nums[i] < 0 ){
               nums[i] *= -1; k--;
            }
            sum += nums[i];
            mn = min(mn, nums[i]);
        }
        // if k is odd we filp the smallest number
        // even => we change nothing
        if(k % 2 == 1){ 
          sum -= (2* mn); // we multiplied  the number with 2 
                        // beacuse we already add it.
        } 
        return sum;
    }
};