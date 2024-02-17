/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        if (mp.find(node->val) == mp.end()) {
            mp[node->val] = new Node(node->val);
            for (Node* neighbor : node->neighbors) {
                mp[node->val]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return mp[node->val];
    }
};