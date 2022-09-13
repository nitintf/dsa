# Problem -> https://www.hackerrank.com/challenges/balanced-brackets/problem
from stack import Stack

str1 = '{[()]}'
str2 = '{[(])}'
str3 = '{{[[(())]]}}'


def isBalanced(s):
    bracketsStack = Stack()

    for char in s:
        if char in ['{', '(', '[']:
            bracketsStack.push(char)
        elif char in ['}', ')', ']']:
            lastOpeningBracket = bracketsStack.pop()
            if lastOpeningBracket == '{' and char == "}":
                continue
            elif lastOpeningBracket == '[' and char == "]":
                continue
            elif lastOpeningBracket == '(' and char == ")":
                continue
            else:
                return 'NO'
    if bracketsStack.size != 0:
        return 'NO'
    else:
        return 'Yes'


if __name__ == '__main__':
    res = isBalanced(str1)
    print(res)
