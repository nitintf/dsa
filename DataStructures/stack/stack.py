from collections import deque


class Stack:
    def __init__(self) -> None:
        self.container = deque()

    def push(self, el):
        self.container.append(el)

    def pop(self):
        return self.container.pop()

    def peek(self):
        return self.container[-1] if not self.is_empty() else 0

    def is_empty(self):
        return len(self.container) == 0

    def print(self):
        for res in self.container:
            print(res)


if __name__ == '__main__':
    stack = Stack()
    stack.push(1)
    stack.push(10)
    stack.push(13)
    stack.push(14)
    stack.pop()
    stack.print()
