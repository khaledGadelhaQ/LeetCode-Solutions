/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(!headA || !headB) return nullptr;
       int a {0} , b {0} ;

       ListNode* ptr = headA;
       ListNode* ptr2 = headB;

       while(ptr){ a++ ; ptr = ptr->next;}
       while(ptr2){ b++ ; ptr2 = ptr2->next;}

       int diff = abs(a-b);
       
       if(a > b) while(diff){ headA = headA->next ; diff--; }
       else while(diff){ headB = headB->next ; diff--; }

       
       while(headA && headB){
           if(headA == headB) return headA;
           headA = headA->next;
           headB = headB->next;
        }
        return nullptr; 

    }
}; 