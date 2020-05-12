class TreeRoot():
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None

class BinarySearchTree():
    def Search(self, root, x):
        if root == None:
            return False
        if x < root.data:
            return self.Ssearch(root.left, x, root)
        if x > root.data:
            return self.Search(root.right, x, root)
        return True

    def Insert(self, root, x):
        if root == None:
            root = TreeRoot(x)
            return root
        if x < root.data:
            root.left = self.Insert(root.left, x)
        else:
            root.right = self.Insert(root.right, x)
        return root

    def Delete(self, root, x):
        if root == None:
            return None
        if x < root.data:
            root.left = self.Delete(root.left, x)
        if x > root.data:
            root.right = self.Delete(root.right, x)
            
        if root.left == None:
            root = root.right
            return root

        if root.right == None:
            root = root.left
            return root

        tmp = root.left
        while tmp.right:
            tmp = tmp.right
        root.data = tmp.data
        root.left = self.Delete(root.left, root.data)
        return root

    def ListRoot(self, root):
        if root:
            return self.ListRoot(root.left) + [root.data] + self.ListRoot(root.right)
        return []

if __name__ == '__main__':
    Tree = BinarySearchTree()
    root = None
    list = [3, 4, 1, 2]
    for i in range(len(list)):
        root = Tree.Insert(root, list[i])
    root = Tree.Delete(root, 2)
    print(Tree.ListRoot(root))