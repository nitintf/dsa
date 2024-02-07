#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  int minFallingPathSumHelper(vector<vector<int>>& matrix, int m, int n, int i, int j, vector<vector<int>>& dp) {
    if (j < 0 || j >= n) {
      return 1e9;
    }

    if (i == m - 1) {
      return dp[i][j] = matrix[i][j];
    }

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int bottom = minFallingPathSumHelper(matrix, m, n, i + 1, j, dp);
    int bottomRight = minFallingPathSumHelper(matrix, m, n, i + 1, j + 1, dp);
    int bottomLeft = minFallingPathSumHelper(matrix, m, n, i + 1, j - 1, dp);

    return dp[i][j] = min(bottom, min(bottomRight, bottomLeft)) + matrix[i][j];
  }

  int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int result = INT_MAX;

    for (int j = 0; j < m; j++) {
      int minPathSum = minFallingPathSumHelper(matrix, m, n, 0, j, dp);
      result = min(result, minPathSum);
    }

    return result;
  }

  int minFallingPathSumTabulation(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
  }
};

int main() {}
