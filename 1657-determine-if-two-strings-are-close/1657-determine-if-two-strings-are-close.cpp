class Solution {
public:
    bool closeStrings(string s, string t) {
        int sz1 = s.size() , sz2 = t.size();
        if(sz1 != sz2) return false;
        vector<int> v(26,0);
        vector<int> v1(26,0);
        for(int i = 0 ; i < sz1 ; i++){
            v[s[i] - 'a'] += 1;
            v1[t[i] - 'a'] += 1;
        }
        for(int i = 0 ; i < 26; i++){
            if(v[i] == 0 && v1[i] != 0) return false;
            if(v1[i] == 0 && v[i] != 0) return false;
        }
        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());
        return v == v1;
    }
};
/*
we have two strings s,t
a[s] = 2 , a[t] = 4
b[s] = 2 , b[t] = 1
c[s] = 4 , c[t] = 3
if we calculted the frequency of every character in the 
two strings then we will foucs only on opeartion 2 

*/