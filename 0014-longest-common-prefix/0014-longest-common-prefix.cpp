class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());

        string first = strs.front();
        string last = strs.back();

        int m = min(first.size(),last.size());
        string res= "";
        for(int i = 0  ; i< m; i++){
          if(first[i] != last[i]){break;}
          res += first[i];
            
        }
        return res;

    }
};