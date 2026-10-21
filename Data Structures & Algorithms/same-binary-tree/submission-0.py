# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        import queue
        q1 = []
        q1.append(p)
        q2 = []
        q2.append(q)

        while q1 and q2:
            n1 = q1.pop()
            n2 = q2.pop()

            if n1 is None and n2 is None:
                continue
            if n1 is None or n2 is None:
                return False

            if n1.val != n2.val:
                return False

            q1.append(n1.left)
            q1.append(n1.right)
            q2.append(n2.left)
            q2.append(n2.right)
        
        return True