class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i < order.size() ; i++){
            mp[order[i]] = i ;
        }
        for(int i = 0 ; i < words.size()-1; i++){
            string fword = words[i];
            string sword = words[i+1];
            for(int j = 0 ; j < fword.size(); j++){
                // if the first word is a prefix of the second one we return false
                if(j == sword.size()) return false;
                if(fword[j] != sword[j]){
                    if(mp[fword[j]] > mp[sword[j]]) return false;
                    break;
                }
                
            }
        }
        return true;

        
    }
};