class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       
        
    int max = arr[arr.size()-1];
    for(int i= arr.size()-2 ; i >= 0 ; i-- ){
        int currrent_val = arr[i] ;
        arr[i] = max;
        if(currrent_val > max){
            max = currrent_val;
        }
       

    }
    arr[arr.size()-1] = -1 ;
        return arr;
    }
};