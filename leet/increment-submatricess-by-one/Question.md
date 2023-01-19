# Increment Submatrices by One

You are given a positive integer `n`, indicating that we initially have an
`n x n` **0-indexed** integer matrix `mat` filled with zeroes.

You are also given a 2D integer array `query`. For each
`query[i] = [row1i, col1i, row2i, col2i]`, you should do the following
operation:

- Add 1 to **every element** in the submatrix with the **top left** corner
  `(row1i, col1i)` and the **bottom right** corner `(row2i, col2is)`. That is,
  add `1` to `mat[x][y]` for for all `row1i <= x <= row2i` and
  `col1i <= y <= col2i`.

Return the `matrix` mat after performing every query.

### Test Case

> Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
>
> Output: [[1,1,0],[1,2,1],[0,1,1]]
>
> Explanation: The diagram above shows the initial matrix, the matrix after the
> first query, and the matrix after the second query.
>
> - In the first query, we add 1 to every element in the submatrix with the top
>   left corner (1, 1) and bottom right corner (2, 2).
> - In the second query, we add 1 to every element in the submatrix with the top
>   left corner (0, 0) and bottom right corner (1, 1).
