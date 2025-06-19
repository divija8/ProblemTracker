class Solution:
    def reorganizeString(self, s: str) -> str:
        count = [0] * 26
        for ch in s:
            count[ord(ch) - ord('a')] += 1
        
        max_freq = max(count)
        max_char = count.index(max_freq)
        
        if max_freq > (len(s) + 1) // 2:
            return ""
        
        res = [""] * len(s)
        idx = 0
        
        while count[max_char] > 0:
            res[idx] = chr(max_char + ord('a'))
            idx += 2
            count[max_char] -= 1
        
        for i in range(26):
            while count[i] > 0:
                if idx >= len(s):
                    idx = 1  
                res[idx] = chr(i + ord('a'))
                idx += 2
                count[i] -= 1
        
        return "".join(res)