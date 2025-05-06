"""

Matrix Multiplication using Strassen's Algorithm

This algorithm improves on the standard divide-and-conquer method by reducing
the number of recursive multiplications from 8 to 7, lowering the time complexity
to approximately O(n^2.81). It is especially useful for large matrices where this
asymptotic improvement becomes noticeable.

Assumptions:
- Input matrices are square (n x n) and n is a power of 2.

"""



def divideMatrix(m):
    n = len(m)
    mid = n // 2

    m11 = [row[:mid] for row in m[:mid]]
    m12 = [row[mid:] for row in m[:mid]]
    m21 = [row[:mid] for row in m[mid:]]
    m22 = [row[mid:] for row in m[mid:]]

    return m11, m12, m21, m22

def addMatrix(m1, m2):
    n = len(m1)
    return [[m1[i][j] + m2[i][j] for j in range(n)] for i in range(n)]

def subtractMatrix(m1, m2):
    n = len(m1)
    return [[m1[i][j] - m2[i][j] for j in range(n)] for i in range(n)]

def combineQuadrants(c11, c12, c21, c22):
    top = [a + b for a, b in zip(c11, c12)]
    bottom = [a + b for a, b in zip(c21, c22)]
    return top + bottom

def matrixMultiplication(a, b):

    n = len(a)

    if n == 1:
        return [[a[0][0] * b[0][0]]]

    # Divide the matrices
    a11, a12, a21, a22 = divideMatrix(a)
    b11, b12, b21, b22 = divideMatrix(b)

    # compute 7 Products
    m1 = matrixMultiplication(addMatrix(a11, a22), addMatrix(b11, b22))
    m2 = matrixMultiplication(addMatrix(a21, a22), b11)
    m3 = matrixMultiplication(a11, subtractMatrix(b12, b22))
    m4 = matrixMultiplication(a22, subtractMatrix(b21, b11))
    m5 = matrixMultiplication(addMatrix(a11, a12), b22)
    m6 = matrixMultiplication(subtractMatrix(a21, a11), addMatrix(b11, b12))
    m7 = matrixMultiplication(subtractMatrix(a12, a22), addMatrix(b21, b22))

    c11 = subtractMatrix(addMatrix(addMatrix(m1, m4), m7), m5)
    c12 = addMatrix(m3, m5)
    c21 = addMatrix(m2, m4)
    c22 = subtractMatrix(addMatrix(addMatrix(m1, m3), m6), m2)

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