def rangeAddQueries(n, queries):
    mat = [[0] * n for _ in range(n)]

    for r1, c1, r2, c2 in queries:
        mat[r1][c1] += 1

        if r2 + 1 < n:
            mat[r2 + 1][c1] -= 1
        if c2 + 1 < n:
            mat[r1][c2 + 1] -= 1
        if r2 + 1 < n and c2 + 1 < n:
            mat[r2+1][c2+1] -= 1

    for r in range(1, n):
        for c in range(n):
            mat[r][c] += mat[r - 1][c]

    for r in range(n):
        for c in range(1, n):
            mat[r][c] += mat[r][c - 1]

    return mat


# Test Case 1
def printMatrix(matrix):
    print("Matrix")
