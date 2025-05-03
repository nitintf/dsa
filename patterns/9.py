"""
Input: ‘N’ = 3

Output: 

*
**
***
**
*

1
2
3
2
1

"""

def nStarTriangle(n: int) -> None:
    for i in range(2 * n - 1):
        i = i + 1
        r = 2 * n - i if i > n else i
        for _ in range(r):
           print("*", end="") 
        print()

nStarTriangle(5)
print()
nStarTriangle(3)
