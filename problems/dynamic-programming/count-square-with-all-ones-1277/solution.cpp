#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int sum = 0;

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      dp[i][0] = matrix[i][0];
      sum += matrix[i][0];
    }

    for (int j = 1; j < m; j++) {
      dp[0][j] = matrix[0][j];
      sum += matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == 0) {
          dp[i][j] = 0;
          continue;
        }

        int minEl = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
        dp[i][j] = matrix[i][j] + minEl;
        sum += dp[i][j];
      }
    }

    return sum;
  }
};

int main() {}
