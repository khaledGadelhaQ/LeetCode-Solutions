class Solution {
public:
string removeDuplicates(string name) {
  string ans ;
  stack<char> s ;
  for(int i = name.size()-1 ; i >= 0 ; i--){
    if(s.empty() || s.top() != name[i])
      s.push(name[i]);
    else if(s.top() == name[i])
      s.pop();
      
  }
  while(!s.empty()){
    ans += s.top(); 
    s.pop();
  }
  return ans ;
}
};