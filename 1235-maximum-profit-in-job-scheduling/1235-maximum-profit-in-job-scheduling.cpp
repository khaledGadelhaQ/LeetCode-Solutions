const int MAX = 50000 + 5;
int memo[MAX];

class Solution {
public:
    int dp(int idx, vector<vector<int>>& arr) {
        if (idx == (int) arr.size()) return 0;
        
        auto &ref = memo[idx];
        if (ref != -1) return ref;
        // Binary Search
        int l = idx +1 , r = arr.size()-1;
        int nextIdx = r + 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid][0] >= arr[idx][1]){
                nextIdx = mid;
                r = mid -1;
            }else{
                l = mid +1 ;
            }
        }
        
        int leave = dp(idx + 1, arr);
        int pick =  arr[idx][2] + dp( nextIdx, arr);

        return ref = max(leave, pick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(memo, -1, sizeof(memo));
        vector<vector<int>> arr;
        for(int i = 0 ; i < profit.size() ;i++){
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(arr.begin(), arr.end());
        return dp(0,arr);
    }
};
