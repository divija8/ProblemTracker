# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxi = float('-inf')

        def maxSum(node, m):
            if not node:
                return 0
            left = max(0, maxSum(node.left, self.maxi))
            right = max(0, maxSum(node.right, self.maxi))
            self.maxi = max(self.maxi, left + right + node.val)
            return max(left, right) + node.val
        maxSum(root, self.maxi)
        return self.maxi