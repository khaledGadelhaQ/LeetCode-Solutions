class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
   stack<int>s ;
  for(int i = v.size()-1 ; i >= 0 ; i--){

    if(s.empty()){
      s.push(v[i]);
    }else if(v[i] < 0){
      s.push(v[i]);
    }else{
      if(s.top() > 0){
        s.push(v[i]);
      }else{
        int cur = v[i];
        while(true){

          if(s.empty() || s.top() > 0){
            s.push(cur); 
            break;
          } else if(abs(s.top()) > cur){
            break;
          }else if(abs(s.top()) < cur){
            s.pop();
          }else{ 
            s.pop(); break;
          }
        }
        
      }
    }

  }
  v.clear();
  while(!s.empty()){
    v.push_back(s.top()); s.pop();
  }
  return v;
    }
};