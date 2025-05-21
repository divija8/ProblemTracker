class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        def markRow(n, m, matrix, i):
            for j in range(m):
                if matrix[i][j] != 0 and matrix[i][j] != float('inf'):
                    matrix[i][j] = float('inf')
        
        def markColumn(n, m, matrix, j):
            for i in range(n):
                if matrix[i][j] != 0 and matrix[i][j] != float('inf'):
                    matrix[i][j] = float('inf')
        
        n = len(matrix)
        m = len(matrix[0])

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    markRow(n, m, matrix, i)
                    markColumn(n, m, matrix, j)

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == float('inf'):
                    matrix[i][j] = 0