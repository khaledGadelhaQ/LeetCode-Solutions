class Solution {
public:
 int evalRPN(vector<string>& postfix) {
   stack<int> s;
    
  for( int i = 0 ; i < (int) postfix.size() ; i++){

    string c = postfix[i];
    if(c == "+")
      calc(1,s);
    else if(c == "-")
      calc(2,s);   
    else if(c == "*")
      calc(3,s); 
    else if(c == "/") 
      calc(4,s);
    else{
      int num = stoi(c);
      s.push(num);
    }

  }


  return s.top();
 }
    void calc(int num, stack<int> &s){
      int first = s.top();
      s.pop();
      int secound = s.top();
      s.pop();   
      if(num == 1){

       s.push(first+secound);
  
      }else if(num == 2){
  
       s.push(secound - first);
        
      }else if(num == 3){

       s.push(first*secound);
        
      }else if(num == 4) {

       s.push(secound / first);

      }
    
    }
};