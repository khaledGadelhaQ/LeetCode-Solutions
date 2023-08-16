class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int k {0} ;
  
    for(int i = 0 ; i< arr.size() ; i++){
        if(arr[i] % 2 == 0  ){
           if(arr[k] % 2 != 0 )
             swap(arr[i] ,arr[k]);
           
        }if(arr[k] % 2 == 0 ){
            k++;
        }
        
    }
        return arr;
    }
};