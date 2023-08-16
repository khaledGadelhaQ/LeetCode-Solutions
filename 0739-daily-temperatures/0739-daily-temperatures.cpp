class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        stack<int> s ;
        for(int i = 0 ; i < (int) nums.size() ; i++){

            while(!s.empty() && nums[i] > nums[s.top()]){

                int k = s.top() ;
                s.pop() ;
                ans[k] = i-k;
            }
            s.push(i);
        }
        return ans;
    }
};