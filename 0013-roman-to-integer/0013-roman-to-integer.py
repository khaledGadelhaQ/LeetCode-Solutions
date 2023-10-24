class Solution:
  def romanToInt(self, s: str) -> int:
    mp = {
      'I' : 1,
      'V' : 5,
      'X' : 10,
      'L' : 50,
      'C' : 100,
      'D' : 500,
      'M' : 1000
    }
    res = 0
    for i in range(len(s)):
      if i < len(s)-1 and  mp[s[i]] < mp[s[i+1]] : 
        res += -mp[s[i]]
      else: 
        res += mp[s[i]]

    return res
        