class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        min_heap = [[0, -1]]

        prefix_sum, res = 0, float('inf')
        for i in range(len(nums)):
            prefix_sum += nums[i]

            while min_heap and prefix_sum - min_heap[0][0] >= k:
                res = min(res, i - min_heap[0][1])
                heappop(min_heap)
            
            heappush(min_heap, [prefix_sum, i])

        if res == float('inf'):
            return -1
        return res    