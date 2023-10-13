class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        R,C = len(image),len(image[0])
        OldColor = image[sr][sc]
        if OldColor == color: return image
        dr = [0,0,-1,1]
        dc = [-1,1,0,0]
        def dfs(r,c):
            image[r][c] = color
            for i in range(4):
                nr,nc = r+dr[i],c+dc[i]
                if nr < 0 or nr >= R or nc < 0 or nc >= C or image[nr][nc] != OldColor : continue
                dfs(nr , nc)
        dfs(sr,sc)
        return image
        