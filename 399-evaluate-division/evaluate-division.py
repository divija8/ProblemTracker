class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)
        for (a, b), val in zip(equations, values):
            graph[a].append((b, val))
            graph[b].append((a, 1 / val))

        def bfs(start, end):
            if start not in graph or end not in graph:
                return -1.0
            if start == end:
                return 1.0
            
            queue = deque([(start, 1.0)])
            visited = set([start])

            while queue:
                curr_node, curr_product = queue.popleft()
                if curr_node == end:
                    return curr_product

                for neighbor, weight in graph[curr_node]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append((neighbor, curr_product * weight))
            
            return -1.0

        return [bfs(start, end) for start, end in queries]