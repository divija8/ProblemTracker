class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        one = 0
        two = 0
        zero = 0

        for e in nums:
            if e == 0:
                zero += 1
            elif e == 1:
                one += 1
            elif e == 2:
                two += 1

        
        for i in range(len(nums)):
            if zero != 0:
                nums[i] = 0
                zero -= 1
            elif one != 0:
                nums[i] = 1
                one -= 1
            else:
                nums[i] = 2
                two -= 1
        
        