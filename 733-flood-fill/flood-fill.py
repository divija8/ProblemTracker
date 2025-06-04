from collections import deque
from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows, cols = len(image), len(image[0])
        start_color = image[sr][sc]

        # No change needed if the starting pixel already has the newColor
        if start_color == newColor:
            return image

        queue = deque()
        queue.append((sr, sc))
        image[sr][sc] = newColor

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right

        while queue:
            r, c = queue.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                # Check bounds and if the color matches the original color
                if 0 <= nr < rows and 0 <= nc < cols and image[nr][nc] == start_color:
                    image[nr][nc] = newColor
                    queue.append((nr, nc))

        return image