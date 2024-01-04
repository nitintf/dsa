#include<vector>
#include<iostream>
#include<string>

using namespace std;

int f(int idx, vector<int>& heights, vector<int>& dp) {
  if (idx == 0) return 0;

  if (dp[idx] != -1) return dp[idx];

  int left = f(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
  int right = INT_MAX;

  if (idx > 1) right = f(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);

  return dp[idx] = min(left, right);
}

/**
 * Calculates the frog's jump distance based on the given number of jumps and heights of each jump.
 *
 * @param n The number of jumps.
 * @param heights The heights of each jump.
 *
 * @return The frog's jump distance.
 *
 * @throws None.
*
 * Time Complexity: O(n) where n is the number of jumps.
 * Space Complexity: O(n) + O(n) where n is the number of jumps and dp array.
 */
int frogJump(int n, vector<int>& heights) {
  vector<int> dp(n + 1, -1);
  return f(n - 1, heights, dp);
}


int frogJumpTabular(int n, vector<int>& heights) {
  vector<int> dp(n, 0);

  dp[0] = 0;

  for (int i = 1; i < n; ++i) {
    int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    int sc = INT_MAX;
    if (i > 1) {
      sc = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    }

    dp[i] = min(fs, sc);
  }

  return dp[n - 1];
}

int frogJumpSpaceOptimized(int n, vector<int> heights) {
  int prev2 = 0;
  int prev1 = abs(heights[1] - heights[0]);

  for (int i = 2; i < n;i++) {
    int fs = prev1 + abs(heights[i] - heights[i - 1]);

    int ss = INT_MAX;
    if (i > 1) {
      ss = prev2 + abs(heights[i] - heights[i - 1]);
    }

    int temp = min(fs, ss);

    prev2 = prev1;
    prev1 = temp;
  }

  return prev1;
}

int main() {
  int n = 6;
  vector<int> h = { 10, 20 };
  int res = frogJump(n, h);

  cout << res << endl;

  return 0;
}
