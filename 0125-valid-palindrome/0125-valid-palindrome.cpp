class Solution {
public:
 string convert(string &s){
  string ans = "";
 for(int i = 0 ; i < (int) s.size() ; i++ ){
   if(isalnum(s[i])){
    if(isdigit(s[i]))
      ans += s[i];
    else 
      ans += tolower(s[i]);
   }else{
    continue;
   }
 }
 return ans ;
}

 bool isPalindrome(string s) {
    s = convert(s);
    for(int i = 0 ; i < (int) s.size()/2 ; i++){
      if(s[i] != s[s.size()-1-i])
        return false;
    }     
    return true;
        
  }
};