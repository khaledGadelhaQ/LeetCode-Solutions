const int MAX = 100 + 5;
int memo[MAX];
string str;

int dp(int i) {
    if (i >= str.size())
        return 1;
    if (str[i] == '0')
        return 0;
    if (i == str.size() - 1)
        return 1;
    auto &ref = memo[i];
    if (ref != -1)
        return ref;
    
    int ch1 = dp(i + 1);
    int ch2 = 0;
    int val = (str[i] - '0') * 10 + (str[i + 1] - '0');
    if (val <= 26)
        ch2 = dp(i + 2);
    
    return ref = ch1 + ch2;
}

class Solution {
public:
    int numDecodings(string s) {
        str = s;
        memset(memo, -1, sizeof(memo));
        return dp(0);
    }
};