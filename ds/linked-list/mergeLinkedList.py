from node import Node
from singlyLL import LinkedList


def printLinkedList(head):
    if head is None:
        print("Empty Linked List")
    while head:
        print(head.data)
        head = head.next


def merge_sort(head1, head2):
    x = head1
    y = head2
    z = None
    if not x:
        return y
    if not y:
        return x
    if x and y:
        if x.data <= y.data:
            z = x
            x = z.next
        else:
            z = y
            y = z.next
    while x and y:
        if x.data <= y.data:
            z.next = x
            z = x
            x = z.next
        else:
            z.next = y
            z = y
            y = z.next
    if not x:
        z.next = y
    else:
        z.next = x
    return z


linkedList_1 = LinkedList()
linkedList_1.append(1)
linkedList_1.append(3)
linkedList_1.append(4)

# Linked List 1 -> 1, 3, 4

linkedList_2 = LinkedList()
linkedList_2.append(1)
linkedList_2.append(2)
linkedList_2.append(6)

# Linked list 2 -> 1, 2, 6

# Output -> 1, 1, 2, 3, 4, 6
sortedLinkedList = merge_sort(linkedList_1.head, linkedList_2.head)

printLinkedList(sortedLinkedList)
