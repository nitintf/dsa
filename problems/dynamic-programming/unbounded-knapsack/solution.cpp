#include<vector>
#include<iostream>
#include<string>

using namespace std;

int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
  // Base case: if we're at the first item
  if (ind == 0) {
    return (W / wt[0]) * val[0];
  }

  if (dp[ind][W] != -1)
    return dp[ind][W];

  int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);

  int taken = INT_MIN;
  if (wt[ind] <= W)
    taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

  return dp[ind][W] = max(notTaken, taken);
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
  vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table

  return knapsackUtil(wt, val, n - 1, W, dp);
}

int unboundedKnapsackTabulation(int n, int W, vector<int>& val, vector<int>& wt) {
  vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

  for (int i = wt[0]; i <= W; i++) {
    dp[0][i] = (i / wt[0]) * val[0];
  }

  for (int idx = 1; idx < n; idx++) {
    for (int w = 0; w <= W; w++) {
      int notTaken = 0 + dp[idx - 1][w];

      int taken = INT_MIN;
      if (wt[idx] <= w)
        taken = val[idx] + dp[idx][w - wt[idx]];

      dp[idx][w] = max(taken, notTaken);
    }
  }

  return dp[n - 1][W];
}

int main() {}
