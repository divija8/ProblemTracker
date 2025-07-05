class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        res = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    cur_res = 4
                    for dr, dy in directions:
                        nr, nc = i + dr, j + dy
                        if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                            cur_res -= 1 
                            
                    res += cur_res
                         
        return res
        