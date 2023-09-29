class Solution {
public:
    int lower_bound(vector<int> &v , int val){
      int l =  0 , r = v.size()-1 ;
      while(l <= r){
        int mid = l + (r-l)/2 ; 
        if(v[mid] < val){ l = mid+1; }
        else{ r = mid-1;}
      }
      return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int indx1 = lower_bound(nums,target);
        int indx2 = lower_bound(nums,target+1)-1;
        
        if( indx1 < (int)nums.size() && nums[indx1]  == target)
          return {indx1, indx2};
        return {-1,-1};
    }
};