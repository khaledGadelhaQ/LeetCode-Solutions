class Solution:
    def colorBorder(self, grid, row, col, color):
        dr = [0, 0, 1, -1]
        dc = [-1, 1, 0, 0]

        def isValid(r, c, R, C):
            if r < 0 or r >= R or c < 0 or c >= C:
                return False
            return True

        def dfs(r, c, grid, visited, oldColor):
            R, C = len(grid), len(grid[0])
            if not isValid(r, c, R, C) or grid[r][c] != oldColor or visited[r][c]:
                return
            visited[r][c] = True
            for i in range(4):
                dfs(r + dr[i], c + dc[i], grid, visited, oldColor)


        def checkForBoundaries(grid, visited, newColor):
            R, C = len(grid), len(grid[0])
            for r in range(R):
                for c in range(C):
                    if not visited[r][c]:
                        continue
                    for d in range(4):
                        nr, nc = r + dr[d], c + dc[d]
                        if not isValid(nr, nc, R, C) or not visited[nr][nc]:
                            grid[r][c] = newColor
                            break

        if grid[row][col] == color:
            return grid

        R, C = len(grid), len(grid[0])
        visited = [[False for _ in range(C)] for _ in range(R)]
        dfs(row, col, grid, visited, grid[row][col])
        checkForBoundaries(grid, visited, color)
        return grid
