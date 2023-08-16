class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;

        map<string , vector<string>> mp ;

        for(auto val : strs){
          string str = val;
          sort(str.begin() , str.end());
          mp[str].push_back(val);
        }
        
        for(auto val : mp){
          res.push_back(val.second);
        }

        return res;
    }
};