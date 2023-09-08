class Solution {
public:
    bool utility(string s, int st , int ed){
     
     while(st < ed){
      if(s[st] == s[ed]){
        st++;
        ed--;
      }else{
        return false;
      }
     }
     return true;
    }
    bool validPalindrome(string s) {
     int st = 0 , ed = s.size()-1 ;
     while(st < ed){
        if(s[st] == s[ed]){
         st++;
         ed--;
        }else{
          return utility(s,st+1 , ed) || utility(s ,st, ed-1);
        }

     }
        return true;

    }
};