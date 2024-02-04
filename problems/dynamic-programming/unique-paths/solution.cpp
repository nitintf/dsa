#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int findUniquePaths(int m, int n, int i, int j, vector<vector<int>>& memo) {
    if (i == m - 1 && j == n - 1) {
      return 1;
    }
    if (i >= m || j >= n) {
      return 0;
    }

    if (memo[i][j] != -1) {
      return memo[i][j];
    }

    return memo[i][j] = findUniquePaths(m, n, i + 1, j, memo) + findUniquePaths(m, n, i, j + 1, memo);
  }

public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> memo(m, vector<int>(n, -1));
    return findUniquePaths(m, n, 0, 0, memo);
  }

  int uniquePathsTabulation(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n;j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        if (i == 0) {
          dp[i][j] = dp[i][j - 1];
        }
        else if (j == 0) {
          dp[i][j] = dp[i - 1][j];
        }
        else {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }

    return dp[m - 1][n - 1];
  }

  int uniquePathsSpaceOptimized(int m, int n) {
    vector<int> prev(n, 0);

    for (int i = 0;i < m; i++) {
      vector<int> curr(n, 0);
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          curr[j] = 1;
        }
        else {
          int up = 0;
          int left = 0;
          if (i > 0) up = prev[j];
          if (j > 0) left = curr[j - 1];
          curr[j] = up + left;
        }
      }
      prev = curr;
    }

    return prev[n - 1];
  }
};

int main() {
  int m = 3, n = 7;
  Solution solution;
  cout << solution.uniquePaths(m, n) << endl;
  return 0;
}
