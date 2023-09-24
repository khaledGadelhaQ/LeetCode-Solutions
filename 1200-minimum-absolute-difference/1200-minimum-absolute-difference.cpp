class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int min {INT_MAX};
        for(int i =1 ; i < arr.size() ; i++){
            int diff = abs(arr[i] - arr[i-1]) ;  

            if( diff > min){continue;}
            if( diff == min){
               ans.push_back({arr[i-1] , arr[i]});
            }else{
                ans.clear();
                min = diff;
                ans.push_back({arr[i-1] , arr[i]});
            }
        }
        return ans;

    }
};