class Node: 
    def __init__(self, data) -> None:
        self.left : Node = None
        self.right : Node = None
        self.data = data

    def printData(self):
        if self.left:
            self.left.printData()
        print(self.data, end=" ")

        if self.right:
            self.right.printData()

        
    def insert(self, data):
        if self.data : 
            if data < self.data : 
                if self.left is None:
                    self.left = Node(data)
                else: 
                    self.left.insert(data)
            if data > self.data: 
                if self.right is None: 
                    self.right = Node(data)
                else: 
                    self.right.insert(data)
        else:
            self.data = data

    # print left -> data -> right
    def inOrderTraversal(self, root):
        res = []

        if root: 
            res = root.inOrderTraversal(root.left)
            res.append(root.data)
            res = res + root.inOrderTraversal(root.right)

        return res

    # print root -> left -> right
    def preOrderTraversal(self, root): 
        res = []

        if root:
            res.append(root.data)
            res = res + root.preOrderTraversal(root.left)
            res = res + root.preOrderTraversal(root.right)
        
        return res

    # print right -> left -> root
    def postOrderTraversal(self, root):
        res= []

        if root: 
            res = root.postOrderTraversal(root.right)
            res = res + root.postOrderTraversal(root.left)
            res = res.append(root.data)

if __name__ == "__main__":
    tree = Node(12)
    tree.insert(1)
    tree.insert(4)
    tree.insert(3)
    tree.insert(2)
    tree.insert(7)
    # tree.printData()
    # print(tree.inOrderTraversal(tree))
    print(tree.preOrderTraversal(tree))
    