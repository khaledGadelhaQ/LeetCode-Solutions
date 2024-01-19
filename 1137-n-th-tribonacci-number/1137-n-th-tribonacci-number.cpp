class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;

        int tmp1 = 0, tmp2 = 1, tmp3 = 1, res = 0;
        for(int i = 3 ; i <= n ; i++){
            res = tmp3 + tmp2 + tmp1;
            tmp1 = tmp2;
            tmp2 = tmp3;
            tmp3 = res;

        }
        return res;
    }
};
