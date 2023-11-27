class Solution {
public:
    const int MAX = 2501;
    int memory[2501];


    int LIS(int i,vector<int>& nums){

        if( i >= nums.size())
            return 0 ;
        
        
        auto &ref = memory[i];
        if(ref != -1)
          return ref;
        ref = 0;
        for (int  j = i+1 ; j < nums.size() ; j++){
            if(nums[j] > nums[i])
               ref = max(ref, LIS(j,nums));
        }
        
        return ++ref;
    }        
    int lengthOfLIS(vector<int>& nums) {
        memset(memory,-1,sizeof(memory));
        nums.insert(nums.begin(),INT16_MIN);
        return LIS(0,nums) - 1 ;
    }
};
/*
this aproach about taking the maximum of every LIS call for every element
in the 'nums' array 
so we consider every element in the array in the output and we start
LIS from this element to find all the element that can are greater thn him
we store the output for every element in a 'memory' array to avoid repeatted work

nice trick is to add a very small value at the beginning of the array so we
make sure that LIS(0)-1 is the optimal solution
Time complexity : O(N^2) 
 N is the number of items and M is the number of valid solution
 for one item
Space complexity: O(N)
 we store N element in the memory array
*/
