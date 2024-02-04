const int OO = 1e5;

struct edge{
    int from,  to;
    int weight;
    edge(int from_, int to_, int w)
        : from(from_), to(to_), weight(w){}
};

vector<int> bellman(vector<edge> &graph, int V , int src){
    vector<int> path(V, OO);
    path[src] = 0; 
    for(int i = 0; i < V ; i++){
        for(auto edge : graph){
            path[edge.to] = min(path[edge.to] , path[edge.from] + edge.weight);
        }
    }
    return path;
}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<edge> graph;
        for(int i = 0 ; i < times.size() ; i++){
            graph.push_back({times[i][0]-1, times[i][1]-1, times[i][2]});
        }
        vector<int> path = bellman(graph, n , k-1);
        int val = *max_element(path.begin(), path.end());
        if(val >= OO) return -1;
        return val;
    }
};