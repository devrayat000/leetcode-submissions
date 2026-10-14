class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        counts = Counter()
        for col in grid:
            counts += Counter(col)
        comp = Counter(range(1, n*n+1))
        
        dbl = counts - comp
        a = max(dbl, key=dbl.get)
        nn = comp - counts
        b = max(nn, key=nn.get)
        return [a, b]