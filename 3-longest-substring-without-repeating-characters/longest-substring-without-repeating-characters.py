class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        map_char = defaultdict(int)
        left = 0
        res = 0
        for right in range(len(s)):
            if s[right] in map_char:
                left = max(left, map_char[s[right]] + 1)
            map_char[s[right]] = right
            res = max(res, right - left + 1)
        return res
        