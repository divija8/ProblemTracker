class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj = {}

        for u, v in prerequisites:
            if v not in adj:
                adj[v] = []
            adj[v].append(u)
            indegree[u] += 1
        from collections import deque

        q = deque()

        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        
        topo = []
        while q:
            node = q.popleft()
            topo.append(node)

            if node not in adj:
                continue
            
            for nei in adj[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)
        return len(topo) == numCourses