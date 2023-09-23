class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      if(nums.size() < 3){
          return ans;
      }
      sort(nums.begin(),nums.end());
    
      int st = 0;

      while(st < nums.size()-2){
        int l = st+1, r = nums.size()-1;
        while(l < r){
          int sum = nums[st] + nums[l] + nums[r];
          if(st != 0 && nums[st] == nums[st-1]){
           break;
          }
          if(sum > 0){
              r--;
          }else if(sum < 0){
              l++;
          }else{
            vector<int> v;
            v.push_back(nums[st]);
            v.push_back(nums[r]);
            v.push_back(nums[l]);
            ans.push_back(v);
            
            while(l < r && nums[l] == nums[l+1]){
                l++;
            }
            l++;
            while(l < r && nums[r] == nums[r-1]){
                r--;
            }
            r--;
          }
        }
        st++;

       }
       return ans;

    }
};