# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        n = len(lists)

        min_heap = []
        for i in range(n):
            curr = lists[i]

            while curr: 
                heapq.heappush(min_heap, curr.val)
                curr = curr.next


        res = ListNode(-1)
        curr = res
        while min_heap:
            node_val = heapq.heappop(min_heap)
            node = ListNode(node_val)
            curr.next = node
            curr = node
        
        return res.next
