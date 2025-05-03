"""
Input: ‘N’ = 3

Output: 

A
A B
A B C
"""

def nLetterTriangle(n: int) -> None:
    for i in range(n):
        start = 65
        for _ in range(i + 1):
            print(chr(start), end = " ")
            start += 1
        print()

nLetterTriangle(3)