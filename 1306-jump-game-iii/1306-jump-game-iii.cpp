class Solution {
public:
    bool bfs(vector<int>& arr, vector<int>& visited, queue<int> &q ,int indx){
        if(indx < 0 || indx >= arr.size() || visited[indx]) 
          return false;
        if(arr[indx] == 0) return true;
        q.push(indx);
        visited[indx] = 1;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0 ) return true;
        vector<int> visited(arr.size(), 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(bfs(arr,visited,q ,front + arr[front])||
            bfs(arr,visited, q ,front - arr[front])){
                return true;
            }
        }
        return false;
    }
};