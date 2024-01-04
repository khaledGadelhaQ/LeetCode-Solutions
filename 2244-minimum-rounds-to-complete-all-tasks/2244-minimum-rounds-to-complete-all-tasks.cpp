class Solution {
public:
    int minimumRounds(vector<int>& nums) {
       int res = 0 ;
        unordered_map<int,int> mp;
        for(auto &val : nums){
            mp[val]++;
        }
        for(auto &val : mp){
            if(val.second == 1 ) return -1;
            int n = val.second;
            if( n % 3 == 0){
                res += (n/3);
            }else{
                res += (n/3 + 1);
            }
        }
        return res; 
    }
};