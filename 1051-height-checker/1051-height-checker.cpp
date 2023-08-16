class Solution {
public:
    int heightChecker(vector<int>& arr) {
            vector<int> arr2 =arr ;
    int k{0} ;

    sort(arr2.begin(),arr2.end());
    for(int i = 0 ; i < arr2.size() ; i++){
        if(arr[i] != arr2[i]){
            k++;
        }
    }
    return k ;
    }
};