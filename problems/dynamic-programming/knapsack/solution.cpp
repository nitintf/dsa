#include<vector>
#include<iostream>
#include<string>

using namespace std;

int knapsackHelper(int n, vector<int> weight, vector<int> value, int idx, int maxWeight, vector<vector<int>>& dp) {
  if (maxWeight == 0) {
    return 0;
  }

  if (idx == n - 1) {
    if (maxWeight >= weight[idx]) {
      return value[idx];
    }
    return 0;
  }

  if (dp[idx][maxWeight] != -1) {
    return dp[idx][maxWeight];
  }

  int notPick = knapsackHelper(n, weight, value, idx + 1, maxWeight, dp);

  int pick = 0;
  if (maxWeight >= weight[idx]) {
    pick = value[idx] + knapsackHelper(n, weight, value, idx + 1, maxWeight - weight[idx], dp);
  }

  return dp[idx][maxWeight] = max(pick, notPick);
}

int knapsackMemoization(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  return knapsackHelper(n, weight, value, 0, maxWeight, dp);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<vector<int>> dp(2, vector<int>(maxWeight + 1, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= maxWeight; ++j)
    {
      if (weight[i] <= j)
      {
        dp[i % 2][j] = max(value[i] + dp[(1 + i) % 2][j - weight[i]], dp[(i + 1) % 2][j]);
      }
      else
      {
        dp[i % 2][j] = dp[(i + 1) % 2][j];
      }
    }
  }

  return dp[(n + 1) % 2][maxWeight];
}

int main() {}
