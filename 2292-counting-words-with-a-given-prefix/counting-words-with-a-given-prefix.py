class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        count = 0
        n = len(pref)
        for word in words:
            s = word[0:n]
            if s == pref:
                count+=1
        return count  