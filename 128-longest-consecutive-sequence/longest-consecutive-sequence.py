class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set(nums)
        longest = 0

        for num in seen:
            if num-1 not in seen:
                curr_num = num
                count = 1
                while curr_num + 1 in seen:
                    count += 1
                    curr_num += 1
                longest = max(longest, count)

        return longest