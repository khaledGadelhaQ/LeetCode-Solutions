class Solution {
public:
    bool isValid(string s) {
 if(s.size() == 1){
  return false;
 }
 map<char,char> m ;
 m['}'] = '{';
 m[')'] = '(';
 m[']'] = '[';

 stack<char> st ;

 for(int i = 0 ; i < s.size() ; i++){
  if(m.count(s[i])){

    if(!st.empty()){
      if(st.top() == m[s[i]]){
       st.pop();
       continue;
      }
    }

    return false;
  }
  st.push(s[i]);


 }
 if(!st.empty()){
  return false;
 }
 
 return true ;

    }
};