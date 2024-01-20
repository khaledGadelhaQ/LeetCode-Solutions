class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sz = arr.size();
        int sum = 0, MOD= 1e9 + 7 ;
        stack<int> stk;
        stk.push(-1);
        for(int j = 0 ; j <= arr.size() ; j++){
            int curVal = (j == arr.size())? 0: arr[j];
            while(stk.top() != -1 && curVal < arr[stk.top()]){
                int x = stk.top(); stk.pop();
                int y  = stk.top();
                int left = x - y;
                int right = j - x ;
                long tmp  = ( (long) left* (long) right * arr[x]);
                tmp %= MOD;
                sum += tmp;
                sum %= MOD;
            }
            stk.push(j);
        }
        return sum;
    }
};