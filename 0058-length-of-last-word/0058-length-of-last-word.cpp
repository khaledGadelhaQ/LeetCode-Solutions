class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1 ; int k {0} ;
       while(n >= 0 && s[n] == ' ') n-- ;
       while(n >= 0 && s[n] != ' ') {n-- ; k++;}
       return k;
    }
};