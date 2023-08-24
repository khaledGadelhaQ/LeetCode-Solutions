class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string,int> mp;
        for(auto val : strs){

            string str ="";
            for(auto c : val){
                str += c; 
                mp[str]++;
            }
        }
        vector<string> v;
        for(auto val  : mp){
            if(val.second == strs.size())
              v.push_back(val.first);
        }
        if(v.empty())
          return "";
        sort(v.begin() , v.end());
        return v.back();
    }
};