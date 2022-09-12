from DataStructures.stack.stack import Stack


def getMax(operations):
    s = Stack()
    res = []
    for operation in operations:
        if len(operation.split()) == 2:
            query, value = operation.split()
        else:
            query = operation
        if query == '1':
            s.push(max(int(value), s.peek()))
        elif query == '2':
            if not s.is_empty():
                s.pop()
        else:
            res.append(s.peek())
    return res


if __name__ == '__main__':
    n = int(input().strip())

    ops = []

    for _ in range(n):
        ops_item = input()
        ops.append(ops_item)

    res = getMax(ops)
