from singlyLL import LinkedList


def findMergeNode(head1, head2):
    while head1 != None:
        q = head2
        while q != None:
            if head1 == q:
                return q.data

            q = q.next
        head1 = head1.next
    return 0


linkedList_1 = LinkedList()
linkedList_2 = LinkedList()
