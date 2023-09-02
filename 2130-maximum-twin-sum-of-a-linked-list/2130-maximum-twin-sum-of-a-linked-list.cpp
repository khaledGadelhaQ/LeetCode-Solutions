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
  int res {0} ;
  ListNode* HEAD {};
  int ans(ListNode* tail){
    if(!tail)
     return 0 ;
    ans(tail->next);
    int n = HEAD->val;
    HEAD = HEAD->next;
    return res = max(res, n + tail->val);
  }
  ListNode* find_mid(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  int pairSum(ListNode* head) {
    HEAD = head;
    return ans(find_mid(head));
  }
};