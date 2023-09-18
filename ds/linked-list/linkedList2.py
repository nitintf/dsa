from node import Node


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def __iter__(self):
        current = self.head
        while current:
            yield current
            current = current.next

    def __str__(self):
        if not self.head:
            return "[]"

        nodes = [str(node.data) for node in self]
        return f"[{', '.join(nodes)}]"

    # O(1)
    def prepend(self, value):
        self.size += 1
        node = Node(value)
        if not self.head:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node

    # O(1)
    def append(self, value):
        self.size += 1
        node = Node(value)
        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node

    #  Work on this
    def insert_after_node(self, prev_node, value):
        if not prev_node:
            print("Previous node is not in list")

        self.size += 1
        node = Node(value)
        node.next = prev_node.next
        prev_node.next = node

    # Best Case - O(1), Worst Case - O(N)
    def remove(self, key):
        if not self.head:
            print("Linked list is empty, node not found")
            return

        curr_node = self.head
        prev_node = None

        if curr_node.data == key:
            self.size -= 1
            self.head = curr_node.next
            return

        curr_node = curr_node.next
        while curr_node and curr_node.data != key:
            prev_node = curr_node
            curr_node = curr_node.next

        if curr_node is None:
            print("Node not found")
            return

        self.size -= 1
        if curr_node == self.tail:
            self.tail = prev_node

        prev_node.next = curr_node.next

    def remove_at_pos(self, pos):
        curr_node = self.head

        # Best case O(1)
        if pos == 0:
            self.size -= 1
            self.head = curr_node.next
            return

        prev_node = None
        count = 0

        #  Worst Case O(N)
        while curr_node and count != pos:
            prev_node = curr_node
            curr_node = curr_node.next
            count += 1

        if curr_node is None:
            print("List item not found: out of index")
            return

        prev_node.next = curr_node.next

    def len_iterative(self):
        curr_node = self.head
        count = 0
        while curr_node:
            count += 1
            curr_node = curr_node.next

        print("Count : ", count)

    def len_recursive(self, node):
        if node is None:
            return 0
        return 1 + self.len_recursive(node.next)

    def reverse_iterative(self):
        # A -> B -> C -> D -> 0
        # D -> C -> B -> A -> 0
        curr_node = self.head
        prev_node = None

        while curr_node:
            next_node = curr_node.next
            curr_node.next = prev_node
            prev_node = curr_node
            curr_node = next_node
        self.head = prev_node

    def reverse_recursive(self):
        def recursive_helper(curr_node: Node, prev_node: Node):
            if not curr_node:
                return prev_node




if __name__ == "__main__":
    ll = LinkedList()
    ll.append(1)
    ll.append(1)

    ll.remove(1)

    ll.append(3)
    ll.append(4)
    ll.prepend(2)
    ll.prepend(1)

    ll.remove(1)
    print(ll)

    ll.reverse_iterative()

    print(ll)

    ll.reverse_iterative()

    print(ll)


