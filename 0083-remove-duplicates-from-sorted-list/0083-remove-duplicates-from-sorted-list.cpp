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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
         return nullptr;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head;
        dummy->next = cur;
        while(head){
            if(head->val != cur->val){
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
        }
        if(cur)
          cur->next = nullptr;
        return dummy->next;
    }
};