class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r, c = len(matrix), len(matrix[0])
        cor = []
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                if v == 0:
                    cor.append((i, j))
        for i, j in cor:
            matrix[i] = [0] * c
            for row in matrix:
                row[j] = 0