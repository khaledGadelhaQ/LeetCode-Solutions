# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right: return head
        dummy = ListNode(0)
        dummy.next = head
        head = dummy
        
        preLeft = head
        i = 1
        while i < left:
            preLeft = preLeft.next
            i += 1
        cur = preLeft.next
        prv = None
        nextNode = None
        
        while i <= right:
            nextNode = cur.next
            cur.next = prv
            prv = cur
            cur = nextNode
            i+=1
        
        preLeft.next.next = cur
        preLeft.next = prv
        return head.next
        