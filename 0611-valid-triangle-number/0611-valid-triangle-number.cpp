class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum {0};
        int sz = nums.size();
        for(int i = sz-1 ; i > 1 ; i--){
            
            for(int j = i-1, k = 0; j > k ; ){
                if(nums[i] < nums[k] + nums[j]){
                    sum += j - k;
                    j--;
                }else{
                    k++;
                }
            }
            
        }
        return sum;
    }
};