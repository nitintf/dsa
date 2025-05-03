"""
Input: ‘N’ = 3

Output: 

1         1
1 2     2 1
1 2 3 3 2 1
"""

def numberCrown(n: int) -> None:
    for i in range(n):
        numbers = i + 1
        spaces = 2 * n - 2 * numbers

        # First part: ascending numbers
        for num in range(numbers):
            print(num + 1, end = " ")

        # Middle Spaces
        for _ in range(spaces):
            print(" ", end= " ")

        # Third part: descending numbers
        for num in range(numbers, 0, -1):
            print(num, end = " ")
        print()

numberCrown(4)