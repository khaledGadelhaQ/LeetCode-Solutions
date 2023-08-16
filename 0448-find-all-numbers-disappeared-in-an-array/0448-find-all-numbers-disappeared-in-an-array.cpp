class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>&arr) {
          vector<int> res ;
  set<int> s ;
  int k {0} ;
  for( auto val : arr){
    s.insert(val);
  }
  for(int i = 1 ; i <= arr.size() ; i++ ){
    if(!s.count(i)){
     res.push_back(i);
    }
  }
        return res;
    }
};