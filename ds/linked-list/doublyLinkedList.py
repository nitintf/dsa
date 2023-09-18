class Node:
    def __init__(self, node_data) -> None:
        self.data = node_data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self) -> None:
        self.head = None
        self.size = 0

    def insertAtStart(self, node_data):
        self.size += 1
        newNode = Node(node_data)

        if self.head is None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode

    def insertAtEnd(self, node_data):
        newNode = Node(node_data)
        currentNode = self.head
        prevNode = self.head.prev

        if self.head is None:
            self.head = newNode
        else:
            while currentNode.next is not None:
                currentNode
