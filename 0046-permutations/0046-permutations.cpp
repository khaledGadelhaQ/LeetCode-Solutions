class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    vector<bool> visited;
    void solve(vector<int>& nums){
        if(res.size() == nums.size()){
            ans.push_back(res);
            return;
        }
        
        for(int j = 0 ; j < nums.size() ; j++){
            if(!visited[j]){
                visited[j] = true;
                res.push_back(nums[j]);
                solve(nums);
                res.pop_back();
                visited[j] = false;

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool> (nums.size(), false);
        solve(nums);
        return ans;
    }
};