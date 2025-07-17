class Solution:
    def sortColors(self, nums: List[int]) -> None:
        freq = {0: 0, 1: 0, 2: 0}

        
        for num in nums:
            freq[num] += 1

        index = 0
        for i in range(3):
            val = freq[i]
            nums[index: index + val] = [i] * val
            index += val