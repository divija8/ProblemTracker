class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        numsmap = [0 ] * n
        for l, r in queries:
            numsmap[l] += 1
            if r < n - 1 : numsmap[r + 1] -= 1
        
        s = 0 
        for i in range(n):
            s += numsmap[i]
            if s < nums[i]:
                return False
        return True