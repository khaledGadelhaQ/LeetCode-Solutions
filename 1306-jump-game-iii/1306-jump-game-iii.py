class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if arr[start] == 0: return True
        def bfs(visited,q,indx):
            if indx < 0 or indx >= len(arr) or visited[indx]:
                return False
            if arr[indx] == 0: 
                return True
            q.append(indx)
            visited[indx] = 1
            return False

        visited = [0]*len(arr)
        q = deque()
        q.append(start)
        visited[start] = 1
        while q:
            front = q.popleft()
            if bfs(visited,q,front + arr[front]) or bfs(visited,q,front - arr[front]):
                return True
       
        return False


        

        

        