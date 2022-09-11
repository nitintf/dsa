from node import Node


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    # C -> O(N)
    def print_list(self):
        curr_node = self.head
        while curr_node:
            print(curr_node.data)
            curr_node = curr_node.next

    # C -> O(N) / on empty O(1)
    def append(self, data):
        self.size += 1
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return
        curr_node = self.head
        while curr_node.next:
            curr_node = curr_node.next
        curr_node.next = new_node

    # C -> O(1)
    def prepend(self, data):
        self.size += 1
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # C -> O(1)
    def insert_after_node(self, prev_node, data):
        if not prev_node:
            print("Previoius Node is not in list")
            return
        self.size += 1
        new_node = Node(data)
        new_node.next = prev_node.next
        prev_node.next = new_node

    # C - O(N)
    def delte_node(self, key):
        curr_node = self.head

        if curr_node and curr_node.data == key:
            self.head = curr_node.next
            curr_node = None
            return

        prev_node = None

        while curr_node and curr_node.data != key:
            prev_node = curr_node
            curr_node = curr_node.next

        if curr_node is None:
            return
        prev_node.next = curr_node.next
        self.size -= 1
        curr_node = None

    def delete_node_at_pos(self, pos):
        curr_node = self.head
        if pos == 0:
            self.head = curr_node.next
            curr_node = None
            return
        prev_node = None
        count = 0
        while curr_node and count != pos:
            prev_node = curr_node
            curr_node = curr_node.next
            count += 1
        if curr_node is None:
            return
        prev_node.next = curr_node.next
        self.size -= 1
        curr_node = None

    def len_interative(self):
        curr_node = self.head
        count = 0
        while curr_node:
            count += 1
            curr_node = curr_node.next
        print('count', count)

    def len_recursive(self, node):
        if node is None:
            return 0
        node = node.next
        return 1 + self.len_recursive(node)

    def len_using_size(self):
        return self.size

    def reverse_iterative(self):
        # A -> B -> C -> D -> 0
        # D -> C -> B -> A -> 0
        # A <- B <- C <- D <- 0
        curr_node = self.head
        prev_node = None

        while curr_node:
            next_node = curr_node.next
            curr_node.next = prev_node
            prev_node = curr_node
            curr_node = next_node
        self.head = prev_node

    def reverse_recursive(self):
        # A -> B -> C -> D -> 0
        # D -> C -> B -> A -> 0
        # A <- B <- C <- D <- 0
        def recursive_helper(curr_node, prev_node):
            if not curr_node:
                return prev_node
            next_node = curr_node.next
            curr_node.next = prev_node
            prev_node = curr_node
            curr_node = next_node
            return recursive_helper(curr_node, prev_node)
        self.head = recursive_helper(curr_node=self.head, prev_node=None)


ll = LinkedList()

ll.append(1)
ll.append(2)
ll.append(3)
ll.append(4)

ll.delete_node_at_pos(2)
ll.len_interative()
print('Recursive Length', ll.len_recursive(ll.head))
print('Size', ll.len_using_size())
ll.reverse_recursive()
ll.print_list()
