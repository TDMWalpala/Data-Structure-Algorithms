#AL Tree implementation in python
import  sys
class TreeNode:
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def insert_Node(self,root,key):
        if not root:
            return TreeNode(key)
        elif key < root.key:
            root.left = self.insert_Node(root.left,key)
        else:
            root.right = self.insert_Node(root.right,key)

        root.height = 1 + max(self.getHeight(root.left),self.getHeight(root.right))

        balanceFactor = self.getBalanceFactor(root)

        if balanceFactor > 1:
            if key < root.left.key:
                return self.rightRotate(root)
            else:
                root.left = self.leftRotate(root.left)
                return self.rightRotate(root)

        if balanceFactor <-1:
            if key > root.right.key:
                return self.leftRotate(root)
            else:
                root.right = self.rightRotate(root.right)

        return root

    def getHeight(self,root):
        if not root:
            return 0
        return root.height
    
    def getBalanceFactor(self,root):
        if not root:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.left)

    def leftRotate(self,z):
         y = z.right
         t2 = y.left
         y.left = z
         z.right = t2
         z.height = 1 + max(self.getHeight(z.left),self.getHeight(z.right))
         y.height = 1 + max(self.getHeight(y.left) - self.getHeight(y.right))

         return y

    def rightRotate(self,z):
        y = z.left
        t3 = y.right
        y.right = z
        z.left = t3
        z.height = 1 + max(self.getHeight(z.left)-self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left)- self.getHeight(y.right))

        return y

    def printHelper(self, currPtr, indent, last):
        if currPtr != None:
            sys.stdout.write(indent)
            if last:
                sys.stdout.write("R----")
                indent += "     "
            else:
                sys.stdout.write("L----")
                indent += "|    "
            print(currPtr.key)
            self.printHelper(currPtr.left, indent, False)
            self.printHelper(currPtr.right, indent, True)      
         
myTree = AVLTree()
root = None
nums = [33,9,53,8,21,61,11]
for num in nums:
    root = myTree.insert_Node(root, num)
myTree.printHelper(root, "", True)