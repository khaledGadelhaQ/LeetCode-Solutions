class Solution {
public:
    string removeDuplicates(string name) {
         stack<char> s ;

 for(int i = name.size()-1 ; i >= 0 ; i--){
   if (!s.empty() && name[i] == s.top()) {
      s.pop();
      continue;
   }
   s.push(name[i]);
 }
 string str ="";

 while(!s.empty()){
   str += s.top();
   s.pop();
 }
 return str ;
    }
};