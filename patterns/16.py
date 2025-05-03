"""
Example:
Input: ‘N’ = 3

Output: 
    A
  A B A
A B C B A
"""

def alphaHill(n: int):
    for i in range(n):
        # Calculate starting spaces
        spaces = n - (i + 1)
        
        # Print starting spaces
        print("  " * spaces, end="")

        # Print characters in ascending order
        for j in range(i + 1):
            print(chr(65 + j), end=" ")

        # Print characters in descending order (excluding the peak)
        for j in range(i - 1, -1, -1):
            print(chr(65 + j), end=" ")
            
        print()

alphaHill(3)