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
    bool isPalindrome(ListNode* head) {
        if(head && !head->next) return true;
        ListNode* slow = head , *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        ListNode* prv(nullptr) , *next;
        while(slow){
            next = slow->next;
            slow->next = prv; 
            prv = slow ;
            slow = next ;
        }
        while(prv && head){
            if(prv->val != head->val) return false;
            prv = prv->next;
            head = head->next;
        }
        return true;

    }
};