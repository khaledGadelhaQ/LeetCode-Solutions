class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
    int k {1} , count {1};
    for(int i = 1  ; i< arr.size() ;i++){
      if(arr[i] != arr[i-1]){
        count = 1;
        arr[k++] = arr[i];
        
      } else {
        if(count < 2) arr[k++] = arr[i];
        count++;
      }

    }
        return k ;
    }
};