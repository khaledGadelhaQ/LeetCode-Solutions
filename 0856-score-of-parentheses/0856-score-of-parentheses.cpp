class Solution {
public:
    int scoreOfParentheses(string name) {
 stack<int> s ;
 int last {0} , last2 {0};
 s.push(0);
 for(auto c : name ){
   if(c =='('){

      s.push(0);

   }else{

     last = s.top() ;
     s.pop();
     last2 = s.top() ;
     s.pop();
      s.push(last2 + max(1,2*last));
   }
 }
 return  s.top();
    }
};