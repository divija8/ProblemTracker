# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        min_Heap = []

        for i, l in enumerate(lists):
            if l:
                heapq.heappush(min_Heap, (l.val, i, l))
        
        dummy = ListNode(0)
        curr = dummy

        while min_Heap:
            val, i, node = heappop(min_Heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(min_Heap, (node.next.val, i, node.next))

        return dummy.next
       