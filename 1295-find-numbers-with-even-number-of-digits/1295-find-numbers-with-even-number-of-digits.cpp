class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res {0} ;
        for(int i = 0 ; i < nums.size() ; i++){
            
            int tmp = 0 ;
            while(nums[i]){
                nums[i] /= 10 ;
                tmp++;
            }
            if(tmp % 2 == 0 ){
                res++;
            }
        }
        return res ;
    }
};