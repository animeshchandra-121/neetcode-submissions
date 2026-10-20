# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        def traverse(node):
            if not node:
                return 0

            left_tree = traverse(node.left)
            if left_tree == -1:
                return -1
            
            right_tree = traverse(node.right)
            if right_tree == -1:
                return -1

            difference = abs(left_tree - right_tree)
            if difference > 1:
                return -1

            return max(left_tree, right_tree) + 1
        
        return traverse(root) > 0