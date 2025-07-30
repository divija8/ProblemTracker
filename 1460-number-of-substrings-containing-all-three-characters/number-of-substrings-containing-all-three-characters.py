class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        count = 0
        start = 0
        state_val = {'a' : 0, 'b' : 0, 'c' : 0}

        for end in range(len(s)):
            state_val[s[end]] += 1
        
            while state_val['a'] > 0 and state_val['b'] and state_val['c'] > 0:
                count += len(s) - end
                state_val[s[start]] -= 1
                start += 1
        return count

        