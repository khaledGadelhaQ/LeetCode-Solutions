from typing import List

class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        dr = [0, 0, -1, 1]
        dc = [-1, 1, 0, 0]
        R, C = len(grid1), len(grid1[0])
        # using a list to have a mutable global variable
        is_sub_island = [False]  
        sum_count = 0

        def isValid(r, c, R, C) -> bool:
            if r < 0 or r >= R:
                return False
            if c < 0 or c >= C:
                return False
            return True

        def dfs(r, c, grid1, grid2):
            if not isValid(r, c, R, C) or grid2[r][c] == 0:
                return
            if grid2[r][c] == 1 and grid1[r][c] == 0:
                is_sub_island[0] = False
                return
            grid2[r][c] = 0  # visited

            for i in range(4):
                dfs(r + dr[i], c + dc[i], grid1, grid2)

        for i in range(R):
            for j in range(C):
                if grid2[i][j] == 0:
                    continue
                is_sub_island[0] = True
                dfs(i, j, grid1, grid2)
                sum_count += is_sub_island[0]

        return sum_count
