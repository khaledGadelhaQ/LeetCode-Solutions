const int MAX = (200*100) + 1 ;
int memo[201][MAX];

bool subset_sum(int indx , vector<int> &values, int target){
    if(target < 0)
        return false;
    if(target == 0)
       return true;
    if(indx == (int) values.size())
        return 0;
    auto &ret = memo[indx][target];
    if(ret != -1)
      return ret;
    if(subset_sum(indx+1, values, target))
       return ret =  true;
    return ret = subset_sum(indx+1 , values, target - values[indx]);

}

class Solution {
public:
    bool canPartition(vector<int> nums) {
        memset(memo,-1,sizeof(memo));
        int arr_sum = accumulate(nums.begin(),nums.end(), 0);
        if(arr_sum % 2 != 0 )
           return false; // the sum is odd number - can't be splitted into two parts
        return subset_sum(0,nums,arr_sum/2);
    }
};