"""
Input: ‘N’ = 3

Output: 

A B C
A B
A
"""

def nLetterTriangle(n: int):
    for i in range(n, 0, -1):
        for j in range(i):
            print(chr(65 + j), end = " ")
        print()

nLetterTriangle(3)