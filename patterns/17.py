"""
Example:
Input: ‘N’ = 3

Output: 
C
C B 
C B A
"""

def alphaTriangle(n: int):
    startChar = 65 + (n - 1)
    for i in range(n):
        for j in range(i + 1):
            print(chr(startChar - j), end=" ")
        print()

alphaTriangle(3)
alphaTriangle(1)