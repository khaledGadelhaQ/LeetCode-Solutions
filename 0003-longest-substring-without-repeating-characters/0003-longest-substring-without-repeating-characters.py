class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        left,right,res = 0,0,0
        for right in range(len(s)):
            if s[right] in mp and mp[s[right]] >= left:
                left = mp[s[right]] + 1
            mp[s[right]] = right
            res = max(res, right - left + 1)
        return res