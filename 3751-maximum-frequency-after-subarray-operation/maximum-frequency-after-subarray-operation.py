class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        answer = 0
        for i in range(1, 50 + 1):
            if i == k:
                continue

            maxi = 0
            curr = 0

            for j in nums:
                if j == i:
                    curr += 1
                elif j == k:
                    curr -= 1
                
                maxi = max(maxi, curr)

                if curr < 0:
                    curr = 0

            answer = max(answer, maxi)
            
        return answer + nums.count(k)