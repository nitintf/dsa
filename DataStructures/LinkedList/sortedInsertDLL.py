class Node(object):

    def __init__(self, data=None, next_node=None, prev_node=None):
        self.data = data
        self.next = next_node
        self.prev = prev_node


def sortedInsert(head, data):
    if head == None:
        return Node(data)

    walker = head
    while walker.next != None and walker.data < data:
        walker = walker.next

    if walker.data < data:
        walker.next = Node(data, None, walker)
    elif walker.prev == None:
        node = Node(data, head)
        head.prev = node
        head = node
    else:
        node = Node(data, walker, walker.prev)
        walker.prev.next = node
        walker.prev = node

    return head
