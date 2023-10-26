class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        unordered_map<string,int> s2i;
        unordered_map<char,int> ch2i;
        int n {0} , sz = pattern.size();

        for(string word; iss >> word ; n++){
            if(n == sz || s2i[word] != ch2i[pattern[n]])
              return false;
            s2i[word] = ch2i[pattern[n]] = n + 1 ;
        }
        return n == sz;



    }
};