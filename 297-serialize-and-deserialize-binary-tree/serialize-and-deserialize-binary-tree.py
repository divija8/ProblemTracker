# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        if not root:
            return "N"
        res = []
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            if not node:
                res.append("N")
            else:
                res.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
                
        return ",".join(res)
        

    def deserialize(self, data):
        vals = data.split(",")
        if vals[0] == "N":
            return None
        root = TreeNode(int(vals[0]))
        q = deque()
        q.append(root)
        index = 1
        while q:
            node = q.popleft()
            if vals[index] != "N":
                node.left = TreeNode(int(vals[index]))
                q.append(node.left)
            index += 1
            if vals[index] != "N":
                node.right = TreeNode(int(vals[index]))
                q.append(node.right)
            index += 1
        return root
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))