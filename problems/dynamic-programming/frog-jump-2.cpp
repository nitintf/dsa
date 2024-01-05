#include<vector>
#include<iostream>
#include<string>

using namespace std;

int f(int idx, int k, vector<int>& heights, vector<int>& dp) {
  if (idx == 0) return 0;

  if (dp[idx] != -1) return dp[idx];

  int minSteps = INT_MAX;

  for (int i = 1; i <= k; i++) {
    if (idx - i >= 0) {
      minSteps = min(minSteps, f(idx - i, k, heights, dp) + abs(heights[idx] - heights[idx - i]));
    }
  }

  return minSteps;
}

/**
 * Calculate the jump using dynamic programming.
 *
 * @param n the number of elements in the heights vector
 * @param k the value of k
 * @param heights the vector of heights
 *
 * @return the result of the jump calculation
 *
 * @throws None
 */
int forgJump2(int n, int k, vector<int>& heights) {
  vector<int> dp(n + 1, -1);
  return f(n - 1, k, heights, dp);
}

int frogJump2Tabular(int n, int k, vector<int>& heights) {
  vector<int> dp(n, 0);

  dp[0] = 0;

  for (int i = 1; i <= n - 1; i++) {
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        minSteps = min(minSteps, dp[i - j] + abs(heights[i] - heights[i - j]));
      }

      dp[i] = minSteps;
    }
  }

  return dp[n - 1];
}

int main() {
  return 0;
}
