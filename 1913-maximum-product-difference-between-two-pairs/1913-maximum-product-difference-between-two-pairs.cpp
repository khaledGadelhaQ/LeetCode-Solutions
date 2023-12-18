class Solution {
public:
/*
Time complexity: O(nlogn)
spac complexity: O(1)
*/
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        return (nums[sz-1]*nums[sz-2]) - (nums[0]*nums[1]);
    }
};