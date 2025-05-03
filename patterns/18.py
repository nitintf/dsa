"""
Example:
Input: ‘N’ = 3

Output
* * * * * * 
* *     * * 
*         * 
*         * 
* *     * * 
* * * * * * 
"""

def symmetry(n: int):
    for i in range(2 * n):
        stars = n - i if (i + 1) <= n else (i + 1) - n
        spaces = 2 * ( n - stars )

        for _ in range(stars):
            print("*", end = " ")

        print("  " * spaces, end = "")

        for _ in range(stars):
            print("*", end = " ")

        print()


symmetry(4)