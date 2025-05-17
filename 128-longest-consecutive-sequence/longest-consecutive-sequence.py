class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest_Streak = 0
        num_Set = set(nums)

        for num in num_Set:
            if num - 1 not in num_Set:
                curr_num = num
                curr_Streak = 1
                while curr_num + 1 in num_Set:
                    curr_num += 1
                    curr_Streak += 1
                longest_Streak = max(longest_Streak, curr_Streak)
        return longest_Streak
        
        