class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        index = n+1

        for i in range(n-2, -1, -1):
            # print("fasdfads")
            if nums[i] < nums[i + 1]:
                index = i
                break 
        else:
            nums.reverse()
            return nums
        # print("fasdfadsfsadsad")
        for i in range(n-1, index, -1):
            if nums[i] > nums[index]:
                nums[i], nums[index] = nums[index], nums[i]
                break
        # print(nums)
        nums[index + 1:] = reversed(nums[index + 1 :])
        return nums
        