class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:

        def isValid(r, c, ROWS, COLS):
            if r < 0 or r >= ROWS: return False
            if c < 0 or c >= COLS: return False
            return True

        def atBoundries(r, c, ROWS, COLS):
            if r == 0 or c == 0 or r == ROWS-1 or c == COLS-1: return True
            return False

        def dfs(r, c, grid):
            if not isValid(r, c, len(grid), len(grid[0])) or grid[r][c] == 1: return
            if atBoundries(r, c, len(grid), len(grid[0])):
                self.isAtBoundry = True
            grid[r][c] = 1
            for i in range(4):
                dfs(r + dr[i], c + dc[i], grid)

        ROWS, COLS = len(grid), len(grid[0])
        numOfClosedIslands = 0
        dr = [0, 0, 1, -1]
        dc = [-1, 1, 0, 0]
        for r in range(ROWS):
            for c in range(COLS):
                if not grid[r][c]:
                    self.isAtBoundry = False
                    dfs(r, c, grid)
                    numOfClosedIslands += not self.isAtBoundry
        return numOfClosedIslands



