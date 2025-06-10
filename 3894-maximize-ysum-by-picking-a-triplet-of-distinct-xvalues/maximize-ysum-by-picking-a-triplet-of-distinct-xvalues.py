class Solution:
    def maxSumDistinctTriplet(self, x: List[int], y: List[int]) -> int:

        pairs = sorted(zip(x, y), key = lambda x : x[1], reverse = True)
        seen_x = set()
        total = 0

        for xi, yi in pairs:
            if xi not in seen_x:
                total += yi
                seen_x.add(xi)
            if len(seen_x) == 3:
                return total
        return -1
