class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    void dfs(int val, string &s, string &str, vector<int> &nodes){
        visited[val] = true;
        s += str[val];
        nodes.push_back(val);
        for(auto &neighbour : graph[val]){
            if(!visited[neighbour]){
                dfs(neighbour, s, str, nodes);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        graph = vector<vector<int>> (n);
        visited = vector<bool> (n,false);
        for(auto &val : pairs){
            graph[val[0]].push_back(val[1]);
            graph[val[1]].push_back(val[0]);
        }
        for(int i = 0 ; i < n ; i++){
            if(visited[i]) continue;
            string subStr = "";
            vector<int> nodes;
            dfs(i,subStr,s,nodes);
            sort(nodes.begin(), nodes.end());
            sort(subStr.begin(), subStr.end());
            for(int i = 0 ; i < nodes.size() ; i++){
                s[nodes[i]] = subStr[i];
            }

        }
        return s;
    }
};