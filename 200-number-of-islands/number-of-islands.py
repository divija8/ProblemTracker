class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        ROWS, COLS = len(grid), len(grid[0])


        # def bfs(r, c):
        #     q = deque()
        #     grid[r][c] = "0"
        #     q.append((r, c))
        #     while q:
        #         row,col = q.popleft()
        #         for dr, dc in directions:
        #             nr, nc = dr + row, dc + col
        #             if(nr < 0 or nr >= ROWS or nc < 0 or nc >= COLS or grid[nr][nc] == "0"):
        #                 continue
        #             q.append((nr, nc))
        #             grid[nr][nc] = "0"
        def dfs(r, c):
            if (r < 0 or r >= ROWS or c < 0 or c >= COLS or grid[r][c] == "0"):
                return
            
            grid[r][c] = "0"
            for nr, nc in directions:
                dfs(r + nr, c + nc)
        count = 0
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == "1":
                    dfs(i, j)
                    count += 1
        
        return count

        