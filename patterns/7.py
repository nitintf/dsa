"""
Input: ‘N’ = 3

Output: 

*****    
 ***
  *

rows = 3

0 - 5
1 - 3
2 - 1
"""

def nStarTriangle(n: int) -> None:
    for i in range(n):
        stars = n * 2 - (2 * i + 1)
        spaces = i
        for _ in range(spaces):
            print(" ", end = "")
        for _ in range(stars):
            print("*", end = "")
        for _ in range(spaces):
            print(" ", end = "")
        print()

nStarTriangle(5)