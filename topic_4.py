
class FixedLinkedList:
    def __init__(self, limit):
        self.head = None
        self.limit = limit
        self.size = 0

    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

    def add_order(self, data):
        if self.size >= self.limit:
            print("Order limit reached.")
            return
        new_node = self.Node(data)
        if not self.head:
            self.head = new_node
            self.size += 1
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
        self.size += 1

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print()

# Example usage
if __name__ == "__main__":
    orders = FixedLinkedList(3)
    orders.add_order("Order 1")
    orders.add_order("Order 2")
    orders.display()
    orders.add_order("Order 3")
    orders.add_order("Order 4")
