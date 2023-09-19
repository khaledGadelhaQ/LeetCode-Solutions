class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() , majority = n/2 ;
        unordered_map<int,int> map  {0};
        for(auto &num : nums){
            if(++map[num] > majority) return num;
        }
        return -1;

    }
};