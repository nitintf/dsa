#include <iostream>

using namespace std;

/**
 * Calculates the nth Fibonacci number using dynamic programming (using memoization [top-down]).
 *
 * Time Complexity: O(n) - The function will only calculate each Fibonacci number once, storing it in dp for later use.
 * Space Complexity: O(n) + O(n) - It creates a vector dp to store the calculated Fibonacci numbers and recursion text based.
 *
 * @param n The index of the Fibonacci number to calculate.
 * @param dp A vector to store previously calculated Fibonacci numbers.
 *
 * @return The nth Fibonacci number.
 *
 * @throws None
 */
int fibonacciWithMemo(int n, vector<int>& dp) {
  if (n <= 1) return n;

  if (dp[n] != -1) {
    return dp[n];
  }

  return dp[n] = fibonacciWithMemo(n - 1, dp) + fibonacciWithMemo(n - 2, dp);
}

/**
 * Calculates the nth Fibonacci number using dynamic programming (tabular method [bottom-up]).
 *
 * Time Complexity: O(n) - The loop runs 'n' times, thus linear time complexity.
 * Space Complexity: O(n) - Space required for the dynamic programming table based on the input 'n'.
 *
 * @param n the index of the Fibonacci number to calculate
 *
 * @return the nth Fibonacci number
 *
 * @throws None
 */
int fibonacciWithTabular(int n) {
  vector<int> dp(n + 1, 0);
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}


/**
 * Calculates the nth Fibonacci number using optimized space.
 *
 * Time Complexity: O(n) - The loop runs 'n' times, thus linear time complexity.
 * Space Complexity: O(1) - Only two integer variables are needed, constant space complexity.
 *
 * @param n the index of the Fibonacci number to calculate
 *
 * @return the nth Fibonacci number
 *
 * @throws None
 */
int optimizedFibonacci(int n) {
  if (n <= 1) return n;

  int prev2 = 0, prev = 1;

  for (int i = 2; i <= n; i++) {
    int temp = prev + prev2;
    prev2 = prev;
    prev = temp;
  }

  return prev;
}

int main() {
  int n = 6;
  vector<int> dp(n + 1, -1);
  cout << fibonacciWithMemo(n, dp) << endl;
  cout << fibonacciWithTabular(n) << endl;
  cout << optimizedFibonacci(n);
  return 0;
}
