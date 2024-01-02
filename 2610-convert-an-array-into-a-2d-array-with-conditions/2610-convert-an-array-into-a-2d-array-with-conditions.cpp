class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<vector<int>> ans;
        for(auto &n : nums){
            if(freq[n] >= ans.size()){
                ans.push_back({}); //adding new row
            }
            ans[freq[n]].push_back(n);
            freq[n]++;
        }
        return ans;
    }
};
/*
i am thinking of using a hashmap to store the number of repeatted numbers 
key -> value
5 -> 5 that means the frequency of the 5 is 5 times
so we need at least 5 rows in the vector
*/