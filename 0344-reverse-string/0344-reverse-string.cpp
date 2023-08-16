class Solution {
public:
    
    void reverseString(vector<char>& s ) {
      int start {0} ;
      int end = (int) s.size()-1 ;
      int k = (end+1)/2;
      reverseString2(s  , start , end , k);

    }
    void reverseString2(vector<char>& s, int start , int end , int k){
      if(k == 0 )
        return;
      swap(s[start] , s[end]);
      reverseString2(s, start+1 , end -1 , k-1);
    }
};