class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       
    sort(arr.begin() , arr.end());
    int k {1};
    for(int i = 0  ; i< arr.size()-1 ;i++){
      if(arr[i+1] != arr[i]){
        arr[k++] = arr[i+1];
      }

    }
        return k ;
    }
};