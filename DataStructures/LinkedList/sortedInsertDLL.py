class Node(object):

    def __init__(self, data=None, next_node=None, prev_node=None):
        self.data = data
        self.next = next_node
        self.prev = prev_node


def sortedInsert(head, data):
    if head == None:
        return Node(data, None, None)
    if data <= head.data:
        head.prev = Node(data, head.prev, head)
        newHead = head.prev
        newHead.next = head
        return newHead
    else:
        i = 0
        while head != None and head.data < data:
            if head.next == None:
                head.next = Node(data, head.next, head)
            elif head.next.data > data:
                head.next = Node(data, head.next, head)
            if i == 0:
                newHead = head
            head = head.next
            i += 1
    return newHead
