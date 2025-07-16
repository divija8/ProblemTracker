class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i, j = 0, 0
        sum_val = 0
        ans = float('inf')

        for j in range(len(nums)):
            sum_val += nums[j]

            while sum_val >= target:
                ans = min(ans, j - i + 1)
                sum_val -= nums[i]
                i += 1
        return ans if ans != float('inf') else 0
        