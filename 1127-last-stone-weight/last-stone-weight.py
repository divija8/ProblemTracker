# class Solution:
#     def lastStoneWeight(self, stones: List[int]) -> int:
#         maxHeap = []
#         maxHeap = [-x for x in stones]
#         heapq.heapify(maxHeap)

#         while len(maxHeap) > 1:
#             x = heapq.heappop(maxHeap)
#             y = heapq.heappop(maxHeap)
#             if x > y:
#                 heapq.heappush(maxHeap, x - y)
    
#         maxHeap.append(0)
#         return abs(maxHeap[0])
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            first = heapq.heappop(stones)
            second = heapq.heappop(stones)
            if second > first:
                heapq.heappush(stones, first - second)

        stones.append(0)
        return abs(stones[0])
        