class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0 ;
        unordered_map<int,int> mp;
        for(auto &val : nums){
            mp[val]++;
        }
        for(auto &val : mp){
            if(val.second == 1 ) return -1;
            int n = val.second;
            if( n % 3 == 0){
                res += (n/3);
            }else{
                res += (n/3 + 1);
            }
        }
        return res;

    }
};
/*
=> n % 3 == 0 ? we just return  n / 3 
=>  n % 3 == 1? 
    lets see some examples: 
    10 % 3 = 1 , the optimal choice is 10/3 + 1 = 4 
    ( delete 3 numbers two times and delete 2 numbers two times)
    13 % 3 = 1 , the optimal choice is 13/3 + 1 = 5 
    ( delete 3 numbers three times and delete 2 numbers two times )
=> n % 3 = 2?
    lets see some examples:
    11 % 3 = 2 , the optimal choice is 11/3 + 1
    ( delete 3 numbers 3 times and 2 numbers one time)
*/
