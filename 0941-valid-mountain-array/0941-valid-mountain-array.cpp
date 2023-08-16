class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool mountain_top = false  ;
        if(arr.size() < 3){
            return false ;
        }
        for( int i = 1 ; i < arr.size() ; i++){
            if(arr[0] > arr[1]){
                return false;
            }
            if(arr[i-1] < arr[i] && mountain_top == false ){
                continue;
            } 
            mountain_top = true ;
            if (arr[i] == arr[i-1]){
                return false ;
            }
            if(arr[i] > arr[i-1]){
              return false ;
            }
            
            
           
        }
        if(!mountain_top ){
            return false;
        }
        return true ;
    }
};