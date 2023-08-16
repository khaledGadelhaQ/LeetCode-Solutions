class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for ( int i = 0 ; i < arr.size() ; i++){
            int N = arr[i] ;
            int ND = N*2;
            if(N == 0 ){
                for(int j = i+1 ; j < arr.size(); j++ ){
                    if(arr[i] == arr[j]){
                        return true;
                    }
                }
                continue;
            }
            auto it = find(arr.begin() , arr.end() , ND);
            if(it != arr.end() ){
                
                return true;
            }
        }
        return false;
    }
};