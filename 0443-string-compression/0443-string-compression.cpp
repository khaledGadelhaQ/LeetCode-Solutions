class Solution {
public:
    int compress(vector<char>& chars) {

        int sz = chars.size();
        int i = 0, k = 0  ;
        while(i < sz ){
            int count = 0 ;
            char c =  chars[i];
            while(i < sz && chars[i] == c){
                count++;
                i++;
            }
            chars[k++] = c;
            if(count > 1){
                string num = to_string(count);
                for(int  i =0  ; i < num.size() ; i++){
                    chars[k++] = num[i];
                }
            }
        }
        return k;
        
    }
};