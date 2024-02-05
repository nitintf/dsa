#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int uniquePathsWithObstaclesHelper(vector<vector<int>>& grid, int m, int n, int i, int j) {
    if (i == m - 1 && j == n - 1) {
      return 1;
    }

    if (i >= m || j >= n) {
      return 0;
    }

    if (grid[i][j] == 1) {
      return 0;
    }

    return  uniquePathsWithObstaclesHelper(grid, m, n, i, j + 1) + uniquePathsWithObstaclesHelper(grid, m, n, i + 1, j);
  }

public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    if (grid[m - 1][n - 1] == 1) {
      return 0;
    }

    return uniquePathsWithObstaclesHelper(grid, m, n, 0, 0);
  }

  int uniquePathsWithObstaclesTabulation(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    if (grid[m - 1][n - 1] == 1 || grid[0][0] == 1) {
      return 0;
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[0][0] = 1;
        }
        else if (grid[i][j] == 1) {
          dp[i][j] = 0;
        }
        else if (i == 0) {
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

  int uniquePathsWithObstaclesSpaceOptimized(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
      vector<int> curr(n, 0);
      for (int j = 0; j < n; j++) {
        if (i > 0 && j > 0 && grid[i][j] == 1) {
          curr[j] = 0;
          continue;
        }

        if (i == 0 && j == 0) {
          curr[j] = 1;
          continue;
        }

        int up = 0;
        int left = 0;

        // Check if we can move up and left (if not at the edge of the maze)
        if (i > 0)
          up = prev[j]; // Number of paths from above (previous row)
        if (j > 0)
          left = curr[j - 1]; // Number of paths from the left (current row)

        // Total number of paths to reach (i, j) is the sum of paths from above and left
        curr[j] = up + left;
      }

      prev = curr;
    }

    return prev[n - 1];
  }
};

int main() {}
