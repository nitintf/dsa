def reverse(head):
    currNode = head

    while head != None:
        nextNode = currNode.next
        currNode.next = currNode.prev
        currNode.prev = nextNode
        if not nextNode:
            return currNode
        return reverse(nextNode)


if __name__ == "__main__":
    print("Nitin")
