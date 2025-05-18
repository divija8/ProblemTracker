class Solution:
    def distance(self, p):
        return math.sqrt(p[0]**2 + p[1]**2)
    
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []

        for p in points:
            heapq.heappush(heap, (-1 * self.distance(p), p))

            if len(heap) > k:
                heapq.heappop(heap)

        return [p[1] for p in heap]