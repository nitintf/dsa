"""
Input: ‘N’ = 3

Output: 
A
B B
C C C
"""

def alphaRamp(n: int) -> None:
    start = 65
    for i in range(n):
        for _ in range(i + 1):
            print(chr(start), end = " ")
        start += 1
        print()

alphaRamp(3)