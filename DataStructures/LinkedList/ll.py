class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
        
    def __iter__(self) -> str:
        current = self.head
        while current:
            yield current
            current = current.next

    def __str__(self) -> str:
        if not self.head:
            return "[]"

        nodes = [str(node.data) for node in self]
        return f"[{', '.join(nodes)}]"


    # BC - O(1), WC - O(N)
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
 
   
    # O(1)
    def appendTail(self, data):
        self.size += 1

        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            self.tail.next = new_node
   
    # O(1)
    def prepend(self,data):
        self.size += 1

        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # BC - O(1), WC - O(N)
    def remove(self, key):
        if self.head is None:
            print("Linked List is empty, nothing to remove")
            return

        if self.head.data == key:
            self.size -= 1
            self.head = self.head.next
            return

        curr_node = self.head.next
        prev_node = self.head

        while curr_node and curr_node.data != key:
            prev_node = curr_node
            curr_node = curr_node.next
            
        if curr_node is None:
            print("Node not found")
        
        self.size -= 1
        if curr_node == self.tail: # this case is only  for when we are using tail
            self.tail = prev_node
        
        prev_node.next = curr_node.next

    def insert_at_pos(self, pos, data):
        idx = 0

        new_node = Node(data)
        
        if pos == idx:
            self.size += 1
            new_node.next = self.head
            self.head = new_node
            return
        
        idx += 1

        curr_node = self.head.next
        prev_node = self.head
        
        while curr_node and pos != idx:
            idx += 1
            prev_node = curr_node
            curr_node = curr_node.next

        if curr_node.next == None:
            if pos == idx:
                self.size += 1
                curr_node.next = new_node
            else:
                print("Position out of range")
            return
        
        self.size += 1 
        prev_node.next = new_node
        new_node.next = curr_node
    
    def remove_at_pos(self, pos):
        idx = 0
        
        if pos == idx:
            self.size -= 1
            self.head = self.head.next
            return
        
        idx += 1

        curr_node = self.head.next
        prev_node = self.head

        while curr_node and pos != idx:
            idx += 1
            prev_node = curr_node
            curr_node = curr_node.next

        if curr_node is None:
            print("Position out of range")
            return
        
        self.size -= 1
        
        prev_node.next = curr_node.next
        
    def len_size(self):
        print(self.size)

    def len_iterative(self):
        lent = 0
        curr_node = self.head
        while curr_node:
            lent += 1
            curr_node = curr_node.next
        print(lent)

    # def len_recursive(self):
        



ll = LinkedList()
ll.append(13)
ll.append(12)
ll.append(34)
ll.append(43)
ll.prepend(1)
ll.append(123)

# print(ll)

ll.remove(123)

# print(ll)

ll.insert_at_pos(4, 0)

# print(ll)

ll.remove_at_pos(4)

print(ll)

ll.len_size()
ll.len_iterative()
