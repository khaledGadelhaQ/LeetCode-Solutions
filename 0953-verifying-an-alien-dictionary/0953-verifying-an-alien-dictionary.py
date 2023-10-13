class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        mp = { ch : indx for indx,ch in enumerate(order)}

        for i in range(len(words)-1):
            fword,sword = words[i],words[i+1]
            for j in range(len(fword)):
                if j == len(sword): return False
                if fword[j] != sword[j]:
                    if mp[fword[j]] > mp[sword[j]]: return False
                    break
        return True
        