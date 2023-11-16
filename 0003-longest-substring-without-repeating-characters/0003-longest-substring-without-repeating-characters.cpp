class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, res = 0 ;
        unordered_map<char,int> mp;
        for(int right = 0 ; right < s.size() ; right++){
           if(mp.find(s[right]) != mp.end() && mp[s[right]] >= left) 
              left = mp[s[right]] + 1;
            mp[s[right]] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }

};
/*
Sliding Window approach
intuition:
we want the continuos substring without repeating characters
so we iterate on the string charcter by character when we reach a repeated
character we edit the left of the sliding window to the last occurance of that
character and updating the length every time as we go
we can use HashMap the key is the character and the value it's position

*/
