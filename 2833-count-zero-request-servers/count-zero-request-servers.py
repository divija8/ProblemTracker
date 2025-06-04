class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key = lambda log : log[1])
        indexed_queries = sorted([(q, i) for i, q in enumerate(queries)])
        count = defaultdict(int)
        res = [0] * len(queries)
        active_s = 0
        left, right = 0, 0

        for q_time, q_index in indexed_queries:
            while right < len(logs) and logs[right][1] <= q_time:
                sid = logs[right][0]
                count[sid] += 1
                if count[sid] == 1:
                    active_s += 1
                right += 1
            
            while left < len(logs) and logs[left][1] < q_time -x:
                sid = logs[left][0]
                count[sid] -= 1
                if count[sid] == 0:
                    active_s -= 1
                left += 1
            res[q_index] = n - active_s
        
        return res

        