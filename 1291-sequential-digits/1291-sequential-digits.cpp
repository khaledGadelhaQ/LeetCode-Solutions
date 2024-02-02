class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int n1 = to_string(low).size();
        int n2 = to_string(high).size();
        unordered_map<int,pair<int,int>> mp;
        int num = 1, num2 = 1;
        for(int i = 2; i <= 10 ; i++){
            mp[i-1] = {num,num2};
            num *= 10;
            num2 *= 10;
            num += i;
            num2 += 1;
        }
        vector<int> ans;
        for(int i = n1 ; i <= n2 ; i++){
            int tmp = mp[i].first;
            int tmp2 = mp[i].second;
            for(int j = 0 ; j < (10 - i); j++){
                if(tmp > high) return ans;
                if(tmp >= low && tmp <= high){
                    ans.push_back(tmp);
                }
                tmp += tmp2;
            }
        }
        return ans;

    }
};