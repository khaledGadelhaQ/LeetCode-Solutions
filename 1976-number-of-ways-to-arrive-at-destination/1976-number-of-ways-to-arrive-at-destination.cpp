const long long MOD = 1e9 + 7;
const long long OO = (1e9 + 10) * 200;

struct edge {
    long long  to;
    long long weight;
    edge(long long to_, long long w)
        : to(to_), weight(w) {}

    bool operator <(const edge &e) const {
        return weight > e.weight;
    }
};

int Dijkstra(vector<vector<edge>> &adjList, int V, int src) {
    vector<long long> distance(V, OO);
    distance[src] = 0;

    vector<long long> count (V,0);
    count[src] = 1;

    priority_queue<edge> pq;
    pq.push(edge(src, 0));
    while (!pq.empty()) {

        edge cur = pq.top();
        int idx = pq.top().to;
        pq.pop();

        if (distance[idx] < cur.weight) continue;

        for (auto e : adjList[idx]) {
            int idxx = e.to;
            int w = e.weight;
            if (distance[idxx] > distance[idx] + w) {
                distance[idxx] = distance[idx] + w;
                pq.push({idxx, distance[idxx]});
                count[idxx] = count[idx];
            }else if(distance[idxx] == distance[idx] + w){
                count[idxx] += count[idx];
                count[idxx] %= MOD;
            }
        }
    }
    return count[V-1] ;
}

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<edge>> adjList(n); // Initialize adjacency list with size n
        for (int i = 0; i < roads.size(); i++) {
            int from = roads[i][0], to = roads[i][1], w = roads[i][2];
            adjList[from].push_back({to, w});
            adjList[to].push_back({from, w});
        }
        return Dijkstra(adjList, n, 0);
    }
};
