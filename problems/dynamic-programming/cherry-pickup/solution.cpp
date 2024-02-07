#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int maximumCherryHelper(vector<vector<int>>& grid, int r, int c, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
    // Out of bound
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) {
      return -1e8;
    }

    // Base condition
    if (i == r - 1) {
      if (j1 == j2) {
        return grid[i][j1];
      }
      else {
        return grid[i][j1] + grid[i][j2];
      }
    }


    if (dp[i][j1][j2] != -1) {
      return dp[i][j1][j2];
    }

    int maxi = -1e8;
    for (int a = -1; a <= +1; a++) {
      for (int b = -1; b <= +1; b++) {
        int pathSum = maximumCherryHelper(grid, r, c, i + 1, j1 + a, j2 + b, dp);

        if (j1 == j2) {
          pathSum += grid[i][j1];
        }
        else {
          pathSum += grid[i][j1] + grid[i][j2];
        }

        maxi = max(maxi, pathSum);
      }
    }

    return dp[i][j1][j2] = maxi;
  }


public:
  int maximumCherry(int r, int c, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return maximumCherryHelper(grid, r, c, 0, 0, c - 1, dp);
  }

  int maximumCherryTabulation(int r, int c, vector<vector<int>>& grid) {

  }
};

int main() {}
