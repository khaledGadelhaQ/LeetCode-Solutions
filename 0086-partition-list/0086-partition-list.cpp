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

  ListNode* partition(ListNode* head, int x) {
    if(!head )
     return nullptr;
    if(!head->next)
     return head;
    
   
    ListNode* lower = new ListNode(0);
    ListNode* upper  = new ListNode(0);
    ListNode* l = lower , *u = upper;

    ListNode* cur = head;

    while(cur){
      if(cur->val < x){
        l->next = cur ;
        l = l->next;
      }else{ 
        u->next = cur;
        u = u->next;
      }
      cur = cur->next;
    }
    l->next = upper->next;
    u->next = nullptr;
    

    
    if(!lower)
      return head;

    return lower->next;

  }
};
