
class Node:

    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

# ____________Recursive Approach_________
# def printLevelorder(root):
#     h = height(root)
#     for i in range(1, h+1):
#         printCurrentLevel(root, i)

# def printCurrentLevel(root, level):
#     if root is None:
#         return
#     if level == 1:
#         print(root.data, end=" ")
#     else:
#         printCurrentLevel(root.left, level-1)
#         printCurrentLevel(root.right, level-1)

# def height(node):
#     if node:
#         lheight = height(node.left)
#         rheight = height(node.right)

#         if lheight > rheight:
#             return lheight + 1
#         else:
#             return rheight + 1
#     return 0

# ___________Queue Method____________
def printLevelorder(root):
    if root is None:
        return 

    queue = []

    queue.append(root)

    while len(queue) > 0:

        node = queue.pop(0)
        print(node.data, end = " ")

        if node.left:
            queue.append(node.left)

        if node.right:
            queue.append(node.right)


# Driver's program
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Level order traversal of binary tree is - ")
printLevelorder(root)