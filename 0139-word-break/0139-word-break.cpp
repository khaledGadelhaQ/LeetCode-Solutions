const int MAX = 1000 + 5 ;
int memo[MAX];
class Solution {
private:
    vector<string> words;
    string s;
    int dp(int i){
        if(i == s.size())
            return true;
        if(memo[i] != -1)
            return memo[i];
        
        for(auto &word : words){
            int sz = word.size();
            if( i + sz - 1 > s.size())
                continue;
            if(s.substr(i,sz) == word && dp(i+sz)){
                memo[i] = true;
                return true;
            }

        }
        memo[i] = false;
        return false;

    }    

public:

    bool wordBreak(string s_, vector<string>& wordDict) {
        this->words = wordDict;
        this-> s = s_;
        memset(memo, -1, sizeof(memo));
        return dp(0);
    }

};