class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        node = Node(value)
        temp = self.root
        if temp is None:
            self.root = node
        else:
            while True:
                if temp.value == value :
                    print("Redundant values are not allowed!")
                    break
                if temp.value > value:
                    if temp.left is None:
                        temp.left = node
                        break
                    temp = temp.left
                else:
                    if temp.right is None:
                        temp.right = node
                        break
                    temp = temp.right

    def deletion(self, value):
        temp = self.root
        if temp is None:
            print("Tree is Empty!")
        else:
            while temp.value != value:
                temp3 = temp
                if temp.value > value:
                    if temp.left is None:
                        print("Value not found!")
                        break
                    temp = temp.left
                else:
                    if temp.value < value:
                        if temp.right is None:
                            print("Value not found!")
                            break
                        temp = temp.right
            else:
                while True:
                    if temp.left:
                        temp2 = temp.left
                        while True:
                            if temp2.right:
                                temp3 = temp2
                                temp2 = temp2.right
                            else:
                                temp.value = temp2.value
                                temp = temp2
                                break
                    elif temp.right:
                        temp2 = temp.right
                        while True:
                            if temp2.left:
                                temp3 = temp2
                                temp2 = temp2.left

                            else:
                                temp.value = temp2.value
                                temp = temp2
                                break
                    else:
                            if temp3.left :
                                if temp3.left.value == temp.value :
                                    temp3.left = None
                                temp3.right = None
                            else :
                                temp3.right = None

                            break

    def inorder(self):
        root = self.root
        print("Inorder :", end="")

        def inorderp(root):
            if root:
                inorderp(root.left)
                print(root.value, end=" ")
                inorderp(root.right)
        inorderp(root)
        print()

    def postorder(self):
        root = self.root
        print("Postorder :", end=" ")

        def postorderp(root):
            if root:
                postorderp(root.left)
                postorderp(root.right)
                print(root.value, end=" ")
        postorderp(root)
        print()

    def preorder(self):
        root = self.root
        print("Preorder :", end="")

        def preorderp(root):
            if root:
                print(root.value, end=" ")
                preorderp(root.left)
                preorderp(root.right)
        preorderp(root)
        print()

    def search(self, value):
        temp = self.root
        flag = 0
        if temp is None:
            print("Tree is Empty!")
        else:
            while temp is not None:
                if temp.value == value:
                    flag = 1
                    break
                elif temp.value < value:
                    temp = temp.right
                else:
                    temp = temp.left
            if flag == 1:
                print("Value found in the tree")
                return True
            else:
                print("Value not found in the tree")
                return False


tree = BinarySearchTree()
print("Enter the operations you want to perform :\n1 ,for insertion\n2,for deletion\n3,for printing tree in postorder\n4, in inorder\n5,in preorder \n 6 to exit \n  ")
while True :
    input1 = int(input("Enter the number: "))
    if input1 == 1 :
        tree.insert(int(input("Enter the number you want to insert : ")))
        print()
    elif input1 == 2 :
        tree.deletion(int(input("Enter the you wanna delete :")))
        print()
    elif input1 == 3:
        tree.postorder()
    elif input1 == 4:
        tree.inorder()
    elif input1 == 5:
        tree.preorder()
    elif input1 == 6 :
        break
    else :
        print("Invalid Key !")
