class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v (nums.size() + 1, 0);
        for(int i = 0 ; i < nums.size() ; i++){
            v[nums[i]] += 1;
        }
        int n1, n2;
        for(int i = 1 ; i <= nums.size() ; i++){
            if(v[i] > 1) n1 = i;
            else if(v[i] == 0) n2 = i;
        }
        return {n1,n2};
    }
};