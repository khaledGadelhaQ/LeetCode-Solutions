class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(auto val : matches){
            mp[val[0]];
            mp[val[1]] += 1;
        }
        vector<int> zeros,ones;
        for(auto val : mp){
            if(val.second == 0) zeros.push_back(val.first);
            if(val.second == 1) ones.push_back(val.first);
        }
        return {zeros,ones};
        
    }
};