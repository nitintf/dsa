from stack import Stack


def maxDepth(s):
    res = cur = 0
    for c in s:
        if c == '(':
            cur += 1
            res = max(res, cur)
        if c == ')':
            cur -= 1
    return res


print(maxDepth("(1)+((2))+(((3)))"))
