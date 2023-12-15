class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> set;
        for(auto &path : paths){
            set.insert(path[0]);
        }
        for(auto &path : paths){
            if(set.find(path[1]) == set.end())
                return path[1];
        }
        return "";
    }
};