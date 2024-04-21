#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create adjacency list to represent graph
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        // Create a queue for BFS traversal
        queue<int> q;
        q.push(source);
        
        // Create a set to mark visited nodes
        unordered_set<int> visited;
        visited.insert(source);
        
        // Perform BFS
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            // If current node is the destination, return true
            if (current == destination) 
                return true;
            
            // Explore all neighbors of the current node
            for (auto neighbour : adjList[current]) {
                // If the neighbour is not visited, mark it as visited and add it to the queue
                if (visited.find(neighbour) == visited.end()) {
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
        
        // If destination is not reachable from source, return false
        return false;
    }
};
