class Solution {
public:
    int DFS(int node , int par , vector<vector<int>> & adj , vector<bool>& hasApple){
        int total_time {0} , child_time {0};
      for(auto child : adj[node]){
          ///go to every child
          if(child == par) continue; // we don't want to got back to the parent // it will go for infinte
          child_time =  DFS(child,node , adj , hasApple) ;

          // if any node has collected any number of apples from its children
          // we add +2 to the total time as this node will be the path to the apples
          // if the node is a leaf or not , we check if it marked as true in the (hasApple) vector
          // if so we add +2 .
          if(child_time || hasApple[child]) total_time += 2 + child_time;


      }
      return total_time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        return DFS(0 ,-1,adj , hasApple);
    }
};