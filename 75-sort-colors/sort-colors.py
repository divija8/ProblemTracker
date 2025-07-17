class Solution:
    def sortColors(self, nums: List[int]) -> None:
        c0, c1, c2 = 0, 0, 0
        for i in range(len(nums)):
            if nums[i] == 0 :
                c0 += 1
            elif nums[i] == 1:
                c1 += 1
            else:
                c2 += 1
        
        for i in range(c0):
            nums[i] = 0
        for i in range(c0, c0 + c1):
            nums[i] = 1
        for i in range(c1 + c0, len(nums)):
            nums[i] = 2
        
        