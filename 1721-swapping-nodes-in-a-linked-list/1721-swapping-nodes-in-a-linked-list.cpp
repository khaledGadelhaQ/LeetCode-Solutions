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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head->next) return head;
        ListNode* node1 = nullptr, *node2 = nullptr;
        for(ListNode* cur = head ; cur ; cur = cur->next){
            if(!node2) node2 = nullptr;
            else node2 = node2->next;
            if(--k == 0){
                node1 = cur;
                node2 = head;
            }
        }
        swap(node1->val , node2->val);
        return head;
    }
};
