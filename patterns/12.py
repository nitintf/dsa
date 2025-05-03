"""
Input: ‘N’ = 3

Output: 

1
2 3
4 5 6
"""

def nNumberTriangle(n: int) -> None:
    start = 1
    for i in range(n):
        for _ in range(i + 1):
            print(start, end = " ")
            start += 1
        print()


nNumberTriangle(3)