class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int res = 0;
        int i = 0 , k = 0;
      
        while (i < neededTime.size() && k < neededTime.size()) {
            int sum = 0, mx = 0;
            while ( k < neededTime.size() && s[k] == s[i]) {
                sum += neededTime[k];
                mx = max(mx, neededTime[k]);
                k++;
            }
            res += (sum - mx);
            i = k;
        }
        return res;
    }
};
