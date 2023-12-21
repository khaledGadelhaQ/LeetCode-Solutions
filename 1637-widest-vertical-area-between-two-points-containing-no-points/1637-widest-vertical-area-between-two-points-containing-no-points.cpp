class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int res = 0; 
        for(int i = 0 ; i < arr.size()-1 ; i++){
            res = max(res, arr[i+1][0] - arr[i][0]);
        }
        return res;
    }
};