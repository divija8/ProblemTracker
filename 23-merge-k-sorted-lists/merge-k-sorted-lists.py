# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
   
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_Heap = []

        for i, node in enumerate(lists):
            if node:
                heapq.heappush(min_Heap, (node.val, i, node))
        
        dummy = ListNode(0)
        curr = dummy
        while min_Heap:
            new_val, i, new_node = heapq.heappop(min_Heap)
            curr.next = new_node
            curr = curr.next
            if new_node.next:
                heapq.heappush(min_Heap, (new_node.next.val, i , new_node.next))

        return dummy.next