class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2 )
            return 1;
        int first = 1, sec = 1;
        for(int i = 2 ; i < n ; i++){
          int tmp = sec;
          sec += first;
          first = tmp;
        }
        return sec;
    }
};