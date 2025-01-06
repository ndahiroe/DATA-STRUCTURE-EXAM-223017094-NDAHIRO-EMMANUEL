
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print()

# Heap implementation for auction items
class MaxHeap:
    def __init__(self):
        self.heap = []

    def push(self, item):
        self.heap.append(item)
        self._heapify_up(len(self.heap) - 1)

    def pop(self):
        if len(self.heap) == 0:
            return None
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return root

    def _heapify_up(self, index):
        parent = (index - 1) // 2
        if index > 0 and self.heap[index] > self.heap[parent]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            self._heapify_up(parent)

    def _heapify_down(self, index):
        left_child = 2 * index + 1
        right_child = 2 * index + 2
        largest = index

        if left_child < len(self.heap) and self.heap[left_child] > self.heap[largest]:
            largest = left_child
        if right_child < len(self.heap) and self.heap[right_child] > self.heap[largest]:
            largest = right_child

        if largest != index:
            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            self._heapify_down(largest)

# Example usage
if __name__ == "__main__":
    # Singly Linked List
    linked_list = SinglyLinkedList()
    linked_list.append("Item 1")
    linked_list.append("Item 2")
    linked_list.display()

    # Max Heap
    max_heap = MaxHeap()
    max_heap.push(500)
    max_heap.push(1000)
    max_heap.push(750)
    print("Highest bid:", max_heap.pop())
