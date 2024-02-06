
const long long MOD = 1e9 + 7;
const long long OO = 2000000000 + 10;
const int MAX = 4 * 1e4 + 1;
int memo[MAX];


struct edge{
    long long to;
    long long weight;
    edge(long long to_, long long w)
        : to(to_), weight(w){}
    
    bool operator <(const edge &e) const{
        return weight > e.weight;
    }
};

vector<long long> Dijkstra(vector<vector<edge>> &adjList, int V, int src) {
    vector<bool> visited(V, false);
    vector<long long> distance(V, OO);
    distance[src] = 0;

    priority_queue<edge> pq;
    pq.push(edge(src, 0));

    while (!pq.empty()) {
        int idx = pq.top().to;
        pq.pop();
        if (visited[idx]) continue;
        for (auto e : adjList[idx]) {
            int idxx = e.to;
            int w = e.weight;
            if (distance[idxx] > distance[idx] + w) {
                distance[idxx] = distance[idx] + w;
                pq.push({idxx, distance[idxx]});
            }
        }
        visited[idx] = true;
    }
    return distance;
}

int dp(int src, int target,vector<vector<edge>> &adjList, vector<long long> &distance){
    if(src == target)
        return 1;
    auto &ref = memo[src];
    if(ref != -1) return ref;
    ref = 0;
    for(auto e : adjList[src]){
        if(distance[e.to] < distance[src]){
            ref += dp(e.to , target, adjList, distance);
            ref %= MOD;
        }
    }
    return ref;
}

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<edge>> adjList(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int f = edges[i][0]-1, t = edges[i][1]-1 , w = edges[i][2];
            adjList[f].push_back({t,w});
            adjList[t].push_back({f,w});
        }
        vector<long long> dist = Dijkstra(adjList, n, n-1);
        memset(memo, -1, sizeof(memo));
        return dp(0,n-1, adjList, dist);
    }
};