class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        stack<int> stk;
        vector<int> res(nums.size());
        for(int i = 2*sz -1; i >= 0; i--){
            while(!stk.empty() && nums[i % sz] >= nums[stk.top()]){
                stk.pop();
            }
            res[i % sz] = stk.empty() ? -1 : nums[stk.top()];
            stk.push(i % sz);
        }
        
        return res;
    }
};