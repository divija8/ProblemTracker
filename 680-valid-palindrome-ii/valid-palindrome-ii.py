class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                return self.is_Pal(l + 1, r, s) or self.is_Pal(l, r-1, s)
            l += 1
            r -= 1
        return True
    
    def is_Pal(self, i, j, s1):
        while i < j:
            if s1[i] != s1[j]:
                return False
            i += 1
            j -= 1
        return True 
