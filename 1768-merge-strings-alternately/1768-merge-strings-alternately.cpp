class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int num = min(word1.size(), word2.size());
        string res= "";
        int i {0} ;
        for( i = 0 ; i < num ; i++){
         res += word1[i];
         res += word2[i];
        }
        if(word1.size()>num) res += word1.substr(i);
        else res += word2.substr(i);
        return res;
    }
};