class Solution {
public:
    int minSteps(string s, string t) {
        int n  = 27;
        vector<int> freq(n,0);
        for(int i = 0 ; i < s.size() ; i++){
            freq[s[i] - 'a'] += 1;
            freq[t[i] - 'a'] -= 1;
        }
        int res = 0;
        for(auto val : freq){
            if(val > 0) res += val;
        }
        return res;
    }
};