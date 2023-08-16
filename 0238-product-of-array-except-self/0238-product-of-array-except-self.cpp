class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {

      vector<int> ans(n.size(),1) ;

      int prefix = 1 ;

      for(int i = 0 ; i < (int) n.size() ; i++ ){
        
        ans[i] = prefix;
        prefix *= n[i];
      }
      int postfix = 1;
      
      for( int i = n.size() - 1 ; i >= 0 ; i-- ){
        ans[i] *= postfix ;
        postfix *= n[i];
      }
      return ans ;

    }
};;