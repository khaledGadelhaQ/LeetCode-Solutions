class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char sMap[128] = {0};
        char tMap[128] = {0};
        for(int i = 0 ; i < s.size(); i++){
            if(sMap[s[i]] != tMap[t[i]]) return false;
            sMap[s[i]] = i+1;
            tMap[t[i]] = i+1;
        } 
        return true;
    }
};