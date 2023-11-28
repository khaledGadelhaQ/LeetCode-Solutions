string str1 = "";
string str2 = "";
int memory[1001][1001];

int LCS(int indx1, int indx2){
    
    if(indx1 == str1.size() || indx2 == str2.size()){
        return 0 ; // first case: one or both of the two strings reachs its end 
    }
    auto &ret = memory[indx1][indx2];
    if(ret!= -1)
        return ret;
    // second choice: equal characters
    if(str1[indx1] == str2[indx2])
        return  ret =  1 +  LCS(indx1 +1 , indx2 + 1);
    // third choice: different characters
    else
        ret = max(LCS(indx1 + 1 , indx2), LCS(indx1, indx2 + 1));
    
    return ret ;

}

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        memset(memory, -1 , sizeof(memory));
        str1 = text1;
        str2 = text2;
        return LCS(0,0);
    }
};
