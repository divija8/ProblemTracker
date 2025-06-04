# from collections import Counter
# import heapq

class Solution:
    def reorganizeString(self, s: str) -> str:
        freq = Counter(s)
        maxHeap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(maxHeap)

        ans = []

        while maxHeap:
            first_c, first_ch = heapq.heappop(maxHeap)
            if not ans or first_ch != ans[-1]:
                ans.append(first_ch)
                if first_c + 1 != 0:
                    heapq.heappush(maxHeap, (first_c + 1, first_ch))
            else:
                if not maxHeap:
                    return ''
                second_c, second_ch = heapq.heappop(maxHeap)
                ans.append(second_ch)
                if second_c + 1 != 0:
                    heapq.heappush(maxHeap, (second_c + 1, second_ch))
                heapq.heappush(maxHeap, (first_c, first_ch))

        return ''.join(ans)