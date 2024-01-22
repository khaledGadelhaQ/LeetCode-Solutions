class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry  = k ;
        vector<int> v;
        for(int i = num.size()-1 ; i >= 0 || carry ; i--){
            if(i >= 0){
                carry += num[i];
            }
            v.push_back( carry % 10);
            carry /= 10;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};