
class CircularLinkedList:
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = self.Node(data)
        if not self.head:
            self.head = new_node
            new_node.next = self.head
            return
        last = self.head
        while last.next != self.head:
            last = last.next
        last.next = new_node
        new_node.next = self.head

    def display(self):
        current = self.head
        if not current:
            return
        while True:
            print(current.data, end=" -> ")
            current = current.next
            if current == self.head:
                break
        print()

# Example usage
if __name__ == "__main__":
    cll = CircularLinkedList()
    cll.append("Bidder 1")
    cll.append("Bidder 2")
    cll.display()
