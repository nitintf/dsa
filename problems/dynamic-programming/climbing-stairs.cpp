#include <iostream>

using namespace std;

/**
 * Calculates the number of distinct ways to climb to the top of a staircase with `n` steps using DP (recursive).
 *
 * @param n the number of steps in the staircase
 *
 * @return the number of distinct ways to climb to the top
 *
 * @throws None
 */
int climbStairs(int n) {
  if (n <= 1) return 1;

  int left = climbStairs(n - 1);
  int right = climbStairs(n - 2);

  return left + right;
}

/**
 * Calculates the number of distinct ways to climb to the top of a staircase with n steps.
 *
 * @param n the number of steps in the staircase
 *
 * @return the number of distinct ways to climb to the top of the staircase
 *
 * @throws None
 */
int climbStairsTabular(int n) {
  if (n <= 1) return 1;

  vector<int> dp(n + 1, 0);

  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

/**
 * Calculates the number of ways to climb a staircase of n steps using an optimized approach.
 *
 * @param n The number of steps in the staircase.
 *
 * @return The number of ways to climb the staircase.
 *
 * @throws None.
 */
int climbStairsOptimized(int n) {
  if (n <= 1) return 1;
  if (n == 2) return 2;

  int prev = 1;
  int prev2 = 2;
  int result = 0;

  for (int i = 2; i < n; i++) {
    result = prev + prev2;
    prev = prev2;
    prev2 = result;
  }

  return result;
}


int main() {
  int n = 3;

  int ans = climbStairs(n);

  cout << ans << endl;
}
