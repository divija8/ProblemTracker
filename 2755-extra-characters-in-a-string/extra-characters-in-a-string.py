class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        dp = [0] * (n + 1)

        for i in range(n-1, -1, -1):
            dp[i] = dp[i+1] + 1
            for word in dictionary:
                if i + len(word) <= n and s[i : i + len(word)] == word:
                    dp[i] = min(dp[i], dp[i + len(word)])
                
        return dp[0]