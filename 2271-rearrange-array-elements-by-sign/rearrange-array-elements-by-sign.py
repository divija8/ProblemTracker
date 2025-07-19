class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        p = []
        n = []
        for i in range(len(nums)):
            if nums[i] > 0:
                p.append(nums[i])
            else:
                n.append(nums[i])
        
        i, j = 0, 0
        res = []
        while i < len(p) and j < len(n):
            res.append(p[i])
            res.append(n[j])
            i += 1
            j += 1

        return res