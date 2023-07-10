from collections import deque


class Stack:
    def __init__(self) -> None:
        self.container = deque()
        self.size = 0

    def push(self, el):
        self.size += 1
        self.container.append(el)

    def pop(self):
        self.size -= 1
        return self.container.pop()

    def peek(self):
        return self.container[-1] if not self.is_empty() else 0

    def is_empty(self):
        return self.size == 0

    def print(self):
        for res in self.container:
            print(res)
    
    def length(self):
        print(self.size)


if __name__ == '__main__':
    stack = Stack()
    stack.push(1)
    stack.push(10)
    stack.push(13)
    stack.push(14)
    stack.pop()
    print(stack.peek())
    stack.print()
    stack.length()
