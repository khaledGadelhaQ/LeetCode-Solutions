class Solution {
public:
    void moveZeroes(vector<int>& arr) {
      int k {0} ;
    for(int i = 0 ; i <  arr.size() ; i++ ){
    if(arr[i] != 0 && arr[k] == 0 ){
          arr[k++] = arr[i];
          arr[i] = 0 ;
          
        }
        if(arr[k] != 0){
            k++;
        }
        
       

    }
     
    }
};