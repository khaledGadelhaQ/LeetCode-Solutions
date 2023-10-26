class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        s2i = {}
        ch2i = {}
        n = 0 
        sz = len(pattern)

        for word in words:
            if n == sz or s2i.get(word,-1) != ch2i.get(pattern[n],-1):
                return False
            s2i[word] = ch2i[pattern[n]] = n + 1
            n += 1
        return n == sz
        