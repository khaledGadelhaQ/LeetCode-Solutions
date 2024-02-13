class Solution {
public:
    bool isPalindrome(string &str){
        for(int i = 0 ; i < str.size()/2; i++){
            if(str[i] != str[str.size()-i-1]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &val : words){
            if(isPalindrome(val)) return val;
        }
        return "";
    }
};