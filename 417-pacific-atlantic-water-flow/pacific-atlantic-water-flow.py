class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []
        ROWS, COLS = len(heights), len(heights[0])
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        pacific = set()
        atlantic = set()

        def dfs(r, c, visited, prevheight):
            if(r < 0 or c < 0 or r >= ROWS or c >= COLS or (r, c) in visited or heights[r][c] < prevheight):
                return
            
            visited.add((r, c))
            for nr, nc in directions:
                dfs(nr + r, nc + c, visited, heights[r][c])

        for r in range(ROWS):
            dfs(r, 0, pacific, heights[r][0])
            dfs(r, COLS-1, atlantic, heights[r][COLS-1])

        for c in range(COLS):
            dfs(0, c, pacific, heights[0][c])
            dfs(ROWS-1, c, atlantic, heights[ROWS-1][c])

        res = []
        for r in range(ROWS):
            for c in range(COLS):
                if (r, c) in pacific and (r, c) in atlantic:
                    res.append([r, c])
        return res

    
        