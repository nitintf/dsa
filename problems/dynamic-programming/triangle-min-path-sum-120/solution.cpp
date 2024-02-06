#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  int findMinPathSum(vector<vector<int>>& triangle, int m, int i, int j, vector<vector<int>>& dp) {
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    if (i == m - 1) {
      return triangle[i][j];
    }

    int currRow = triangle[i][j] + findMinPathSum(triangle, m, i + 1, j, dp);
    int prevRow = triangle[i][j] + findMinPathSum(triangle, m, i + 1, j + 1, dp);

    return dp[i][j] = min(currRow, prevRow);
  }

  int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    return findMinPathSum(triangle, m, 0, 0, dp);
  }

  int minimumTotalTabulation(vector<vector<int>>& triangle) {
    int n = triangle.size();
    // Create a 2D DP (dynamic programming) array to store minimum path sums
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++) {
      dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i; j >= 0; j--) {
        // Calculate the minimum path sum for the current cell
        int down = triangle[i][j] + dp[i + 1][j];
        int diagonal = triangle[i][j] + dp[i + 1][j + 1];

        // Store the minimum of the two possible paths in dp
        dp[i][j] = min(down, diagonal);
      }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
  }
};

int main() {}
