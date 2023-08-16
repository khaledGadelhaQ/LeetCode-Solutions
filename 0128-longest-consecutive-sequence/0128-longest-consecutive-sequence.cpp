class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size() == 0)
       return 0;
      if(nums.size() == 1)
        return 1 ;

      sort(nums.begin(),nums.end());
      int len {0} ;
      int n {1};
      
      for(int i = 0 ; i< (int) nums.size()-1 ; i++ ){
        if(nums[i] == nums[i+1])
         continue;
        if(nums[i]+1 == nums[i+1]){
          n++;
        }else{
          len = max(len,n);
          n = 1;
        }
        
      }
      len = max(len,n);

      return len;
   
    }
};