/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr; /// no nodes 
        unordered_map<Node*,Node*> nodes;

        Node* tmp = head;
        while(tmp){
            nodes[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            nodes[tmp]->next = nodes[tmp->next];
            nodes[tmp]->random = nodes[tmp->random];
            tmp = tmp->next;
        }
        return nodes[head];

    }

};









