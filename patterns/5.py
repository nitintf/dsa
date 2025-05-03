"""
Input: ‘N’ = 3

Output: 
* * *
* *
*
"""

def seeding(n: int) -> None:
    for i in range(n):
        for j in range(n - i):
            print("*", end = " ")
        print()