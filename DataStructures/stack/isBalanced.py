# Problem -> https://www.hackerrank.com/challenges/balanced-brackets/problem
from collections import defaultdict

chars = defaultdict(str)

chars['{'] = '}'
chars['['] = ']'
chars['('] = ')'

str1 = '{[()]}'
str2 = '{[(])}'
str3 = '{{[[(())]]}}'


def isBalanced(s):
    isBal = []
    str1, str2 = s[:len(s)//2], s[len(s)//2:]
    list1, list2 = [w for w in str1], [w for w in str2]
    if len(list1) != len(list2):
        return False
    for i in range(len(list1) - 1):
        if chars[list1[0]] == list2[-1]:
            list1.pop(0)
            list2.pop()
            isBal.append(True)
        else:
            isBal.append(False)
    return all(isBal)


if __name__ == '__main__':
    res = isBalanced(str1)
    print(res)
