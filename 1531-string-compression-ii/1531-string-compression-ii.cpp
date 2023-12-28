
    int memo[101][101][27][101]; 
    // i , k , prev character, prev_count
    // i => index it can range from 1 -> 100
    // k => the number of allowed deletions 0 -> 100
    // prev_character there is only 26 characters in english as
    // it will only be in lowercase english letters so it memo it will be 27
    // prev_count it could be 100 
class Solution {
public:

    string str;
    int dp(int i, int k, int prev_ch , int prev_cnt){
        if(k < 0)
            return 1e9;
        if( i >= str.size())
            return 0;

        auto &ref = memo[i][k][prev_ch][prev_cnt];
        if(ref != -1)
            return ref;

        if(str[i] == (prev_ch + 'a')){
            // equal characters we increment only the cnt
            // if cnt == 1,9,99 that means we need to add new digit
            int incr = 0 ;
            if(prev_cnt == 1 || prev_cnt == 9 || prev_cnt == 99){
                incr++;
            }
            ref =  incr + dp(i+1 , k, prev_ch, prev_cnt + 1);
        }else{
            // delete the character
            int choice1 = dp(i+1 , k-1 , prev_ch, prev_cnt);
            // skip dont delete it 
            int choice2 = 1 + dp(i+1, k , str[i] - 'a' , 1);
            ref = min(choice1 , choice2);
        }
        return ref;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        this->str = s;
        memset(memo, -1, sizeof(memo));
        return dp(0, k ,26, 0);
    }
};
