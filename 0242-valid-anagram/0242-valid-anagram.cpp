/*
Time complexity : O(n)
Space complexity: O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(auto val : s){
            mp[val]++;
        }

        for(auto val : t){
            mp[val]--;
        }

        for(auto val : mp){
            if(val.second != 0 )
                return false;
        }

        return true;
    }
};