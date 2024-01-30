class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        long long N = n;
        if(n < 0){
            x = 1/x;
            N = -N;
        }
        double cur = x;
        double res = 1;
        for(long long i = N ; i ; i /= 2){
            if(i % 2 == 1){ //odd
                res *= cur;
            }
            cur *= cur;
        }
        return res;
    }
};