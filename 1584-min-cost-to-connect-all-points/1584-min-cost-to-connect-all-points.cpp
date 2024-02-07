const int OO = 2 * 1e6 * 1000 ;

typedef pair<int,int> pii;

int MST(vector<vector<pii>> &adjList, int V, int src = 0) {
    vector<bool> visited(V, false);
    vector<int> distance(V, OO);
    distance[src] = 0;
    int mnVal = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // using min heap
    pq.push({0, src});
    while (!pq.empty()) {
        auto cur = pq.top();
        int idx = cur.second;
        pq.pop();
        if (visited[idx]) continue;
        mnVal += cur.first; 
        for (auto e : adjList[idx]) {
            int to = e.second;
            int w = e.first;
            if(w < distance[to]){
                distance[to] = w;
                pq.push({w, to});
            }
        }
        visited[idx] = true;
    }
    return mnVal;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<pii>> adjList(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){ 
                int cost = abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]);
                adjList[i].push_back({cost, j});
                adjList[j].push_back({cost, i});
            }
        }
        return  MST(adjList, n);

    }
};
