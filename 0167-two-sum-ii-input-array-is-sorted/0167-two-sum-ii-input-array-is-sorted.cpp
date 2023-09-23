class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> ans;
        int st = 0, ed = v.size() - 1;
        
        while (st < ed) { // Changed 'st != ed' to 'st < ed'
            int sum = v[st] + v[ed];
            
            if (sum == target) {
                ans.push_back(st+1);
                ans.push_back(ed+1);
                return ans;
            } else if (sum > target) {
                ed--;
            } else {
                st++;
            }
        }
        return ans;
    }
};