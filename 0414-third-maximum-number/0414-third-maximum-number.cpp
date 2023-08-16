class Solution {
public:
    int thirdMax(vector<int>& arr) {
          sort(arr.rbegin(), arr.rend() );
    int k {1};
    int thirdMax {0} ;
    for(int i = 0 ; i < arr.size()-1 ; i++){
      if(k == 3){
        
        return  thirdMax;
        
      }
      if(arr[i] != arr[i+1]){
       
        thirdMax = arr[i+1];
        k++;
      }
    }
    
    if(k != 3){
        return  arr[0];
    }
        return thirdMax;
    }
};