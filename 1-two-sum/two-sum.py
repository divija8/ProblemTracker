class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        values = {}
        res = []
        for ind, num in enumerate(nums):
            k = target - num
            if k in values:
                res.append(values[k])
                res.append(ind)
            values[num] = ind
        
        return res
                