class Solution {
public:
    int numberOfSteps(int num) {
        int tmp {0} ;
        while(num){
            if(num % 2 == 0){
                num /= 2 ;
                tmp++;
            }else{
                num -= 1 ;
                tmp++;
            }
        }
        return tmp ;
    }
};