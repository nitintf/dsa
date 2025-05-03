"""
Input: ‘N’ = 3

Output: 

  *
 ***
*****
"""

def nStarTriangle(n: int) -> None:
    for i in range(n):
        stars = 2 * i + 1
        spaces = n - i - 1
        for _ in range(spaces):
            print(" ", end = "")
        for _ in range(stars):
            print("*", end = "")
        for _ in range(spaces):
            print(" ", end = "")
        print()
