"""
Matrix Multiplication using Divide and Conquer (Standard Approach)

This algorithm recursively multiplies two square matrices A and B of size n x n
(assuming n is a power of 2) by breaking them into smaller submatrices.

Steps:
1. Divide each matrix into four (n/2 x n/2) submatrices.
2. Recursively multiply the parts to compute intermediate products.
3. Combine the results to build the final matrix.

Time Complexity: O(n^3)

Why this isn't optimal:
- Although it's a clean recursive approach, it performs 8 recursive multiplications,
  just like the standard iterative method, so its asymptotic complexity is the same.
- Strassen’s algorithm improves on this by reducing the number of recursive multiplications
  from 8 to 7, achieving a time complexity of approximately O(n^2.81), which is faster
  for large matrices.

This implementation is useful as a stepping stone to understanding more advanced
matrix multiplication algorithms like Strassen's or Winograd's.
"""

def divideMatrix(mtx):
    n = len(mtx)
    mid = n // 2

    a11 = [row[:mid] for row in mtx[:mid]]
    a12 = [row[mid:] for row in mtx[:mid]]
    a21 = [row[:mid] for row in mtx[mid:]]
    a22 = [row[mid:] for row in mtx[mid:]]
    
    return a11, a12, a21, a22

def addMatrix(m1, m2):
    n = len(m1)
    return [[m1[i][j] + m2[i][j] for j in range(n)] for i in range(n)]

def combineQuadrants(C11, C12, C21, C22):
    top = [a + b for a, b in zip(C11, C12)]
    bottom = [a + b for a, b in zip(C21, C22)]
    return top + bottom

def matrixMultiplication(a, b):
    n = len(a)

    # Base case: 1x1 matrix
    if n == 1:
        return [[a[0][0] * b[0][0]]]

    # Divide
    a11, a12, a21, a22 = divideMatrix(a)
    b11, b12, b21, b22 = divideMatrix(b)

    # Conquer (8 recursive multiplications)
    m1 = matrixMultiplication(a11, b11)
    m2 = matrixMultiplication(a12, b21)
    m3 = matrixMultiplication(a11, b12)
    m4 = matrixMultiplication(a12, b22)
    m5 = matrixMultiplication(a21, b11)
    m6 = matrixMultiplication(a22, b21)
    m7 = matrixMultiplication(a21, b12)
    m8 = matrixMultiplication(a22, b22)

    # Combine
    c11 = addMatrix(m1, m2)
    c12 = addMatrix(m3, m4)
    c21 = addMatrix(m5, m6)
    c22 = addMatrix(m7, m8)

    return combineQuadrants(c11, c12, c21, c22)


A = [
    [1, 2],
    [3, 4]
]

B = [
    [5, 6],
    [7, 8]
]

print(matrixMultiplication(A, B))