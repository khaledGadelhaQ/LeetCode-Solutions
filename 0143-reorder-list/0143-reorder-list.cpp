/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  void reorderList(ListNode* node){

    if(!node || !node->next || !node->next->next)
      return;
  
    ListNode* node_prv = node;
    while(node_prv->next->next){
      node_prv = node_prv->next;
    }
    
    node_prv->next->next = node->next ;
    node->next = node_prv->next;
    node_prv->next = NULL ;
    node = node->next->next ;

    reorderList(node);
    
  }

};