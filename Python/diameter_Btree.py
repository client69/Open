class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def diameter(root) -> int:
    d = [0]
    def dfs(root):
        if not root:
            return -1
        
        left = dfs(root.left)
        right = dfs(root.right)
        d[0] = max(d[0], left+right+2)
        
        return 1 + max(left, right)
    
    dfs(root)
    return d[0]



root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
# Function Call
print(diameter(root))