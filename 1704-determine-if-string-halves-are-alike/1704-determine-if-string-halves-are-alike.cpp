class Solution {
public:
    bool halvesAreAlike(string s) {
        int sz = s.size();
        unordered_map<int,bool> uMap {
            {'a',true}, {'e',true} , {'i', true} ,{'o',true}, {'u',true},
            {'A',true}, {'E',true} , {'I', true} ,{'O',true}, {'U',true}
        };
        int count1 = 0 ;
        for(int i = 0 ; i < sz/2 ; i++){
            if(uMap[s[i]]) count1++;
        }
        for(int i = sz/2; i < sz ; i++){
            if(uMap[s[i]]) count1--;
        }
        return count1 == 0;
    }
};