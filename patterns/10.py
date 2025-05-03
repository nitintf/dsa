"""
Input: ‘N’ = 3

Output: 

1
0 1
1 0 1
"""

def nBinaryTriangle(n: int) -> None:
    for i in range(n):
        start = 1 if i % 2 == 0 else 0
        for j in range(i + 1):
            print(start, end=" ")
            start = 1 - start
        print()

nBinaryTriangle(5)
print("-----")
nBinaryTriangle(3)