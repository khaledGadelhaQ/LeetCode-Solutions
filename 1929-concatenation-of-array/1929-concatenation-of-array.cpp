class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    nums.resize(2*nums.size());
    for(int i = n ; i<(int) nums.size() ; i++){
      nums[i] = nums[i-n];
    }
    return nums;
    }
};