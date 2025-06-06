class Solution:
    def trap(self, height: List[int]) -> int:
        n, res = len(height), 0
        prefix = [0] * len(height)
        suffix = [0] * len(height)
        prefix[0] = height[0]
        suffix[n-1] = height[n-1]
        for i in range(1, n):
            prefix[i] = max(prefix[i-1], height[i])
        
        for i in range(n-2, -1, -1):
            suffix[i] = max(suffix[i+1], height[i])

        for i in range(n):
            res += min(prefix[i], suffix[i]) - height[i]
        
        return res