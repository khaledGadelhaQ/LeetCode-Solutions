class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1 , r = nums.size()-1;
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int i = 0, j = nums.size()-1 ; i < nums.size() && j >= 0; i++, j--){
            maxVal = max(maxVal, nums[i]);
            if(nums[i] < maxVal) r = i;
            minVal = min(minVal, nums[j]);
            if(nums[j] > minVal) l = j;
        }
        return l == -1? 0 : r - l + 1;
    }
};