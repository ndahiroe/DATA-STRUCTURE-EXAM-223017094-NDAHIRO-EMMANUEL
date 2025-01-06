
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def display(self, level=0):
        print("  " * level + self.data)
        for child in self.children:
            child.display(level + 1)

# Example usage
if __name__ == "__main__":
    root = TreeNode("Auction System")
    category1 = TreeNode("Art")
    category2 = TreeNode("Electronics")
    root.add_child(category1)
    root.add_child(category2)
    category1.add_child(TreeNode("Painting 1"))
    category2.add_child(TreeNode("Laptop 1"))
    root.display()
