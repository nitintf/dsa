"""
Input: ‘N’ = 3

Output: 

  *
 ***
*****
*****
 ***
  *
"""

def printStarsAndSpaces(spaces: int, stars: int) -> None:
    for _ in range(spaces):
            print(" ", end = "")
    for _ in range(stars):
            print("*", end = "")
    for _ in range(spaces):
            print(" ", end = "")
    print()

def nStarDiamond(n: int) -> None:
    for i in range(n):
        topSpaces = n - (i + 1)
        topStars = 2 * i + 1

        printStarsAndSpaces(topSpaces, topStars)

    for j in range(n):
        bottomSpaces = j
        bottomStars = 2 * n - ( 2 * j + 1)

        printStarsAndSpaces(bottomSpaces, bottomStars)
    
nStarDiamond(5)