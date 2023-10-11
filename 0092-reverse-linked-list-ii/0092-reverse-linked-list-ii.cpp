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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;

        ListNode* preLeft = head;

        for (int i = 1; i < left; i++) {
            preLeft = preLeft->next;
        }

        ListNode* cur = preLeft->next;
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;

        for (int i = left; i <= right; i++) {
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        preLeft->next->next = cur;
        preLeft->next = prev;

        return dummy->next;
    }
};
