const int MAX = 1e9 + 7 ; 
unordered_map<int, long long> memo;
unordered_set<int> arr;

class Solution {
private:
    long long dp(int val){
        if(memo.count(val))
            return memo[val];
        long long count = 1;
        for(auto x : arr){
            if(val % x == 0 && arr.count(val / x)){
                count += (dp(x) * dp(val/x)) % MAX;
                count %= MAX;
            }
        }
        return memo[val] = count;
    }
public:
    int numFactoredBinaryTrees(vector<int> nums) {
        memo.clear();
        arr.clear();
        arr.insert(nums.begin(), nums.end());
        long long res = 0;
        for(auto val : nums){
            res += dp(val);
            res %= MAX;
        }
        return res;
    }
};