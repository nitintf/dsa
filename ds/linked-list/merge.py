from ll import LinkedList


def mergeLinkedList(ll1, ll2):
    linked_list = LinkedList()
    curr_node_1 = ll1.head
    curr_node_2 = ll2.head

    while curr_node_1.next and curr_node_2.next:
        if curr_node_1.data < curr_node_2.data:
            linked_list.append(curr_node_1.data)
            curr_node_1 = curr_node_1.next
        else:
            linked_list.append(curr_node_2.data)
            curr_node_2 = curr_node_2.next

    while curr_node_1.next:
        linked_list.append(curr_node_1.data)
        curr_node_1 = curr_node_1.next

    while curr_node_2.next:
        linked_list.append(curr_node_2.data)
        curr_node_2 = curr_node_2.next

    return linked_list


if __name__ == "__main__":
    ll1 = LinkedList()
    ll1.append(2)
    ll1.append(3)
    ll1.append(5)
    ll1.append(8)
    ll1.append(12)

    ll2 = LinkedList()
    ll2.append(1)
    ll2.append(3)
    ll2.append(4)
    ll2.append(6)
    ll2.append(7)
    ll2.append(10)
    ll2.append(11)
    ll2.append(17)

    print(ll1)
    print(ll2)

    merged_list = mergeLinkedList(ll1, ll2)

    print(merged_list)
