int memo[31][1001];
const int MAX = 1000000007 ; 
class Solution {
private:
    int faces , dices;
    int dp(int idx, int amount){
       if(idx == dices) {
            if(amount == 0)
                return 1;
            return 0;
        }
        if(amount <= 0 || idx > dices )
            return 0;
        auto& ref = memo[idx][amount];
        if(ref != -1)
            return ref;
        ref = 0;
        for(int i  = 1 ; i <= faces ; i++){
            ref += dp(idx+1, amount-i);
            ref %= MAX;
        }
        return ref ;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        faces = k;
        dices = n;
        memset(memo, -1, sizeof(memo));
        return dp(0,target);
    }
};

/*
we have n dices and k values from 1 -> k 
so idx can't be more than k but it can be k 
*/