#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int coinChangeHelper(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
    if (idx == 0) {
      if (amount % coins[0] == 0) return amount / coins[0];
      else return 1e9;
    }

    if (dp[idx][amount] != -1) {
      return dp[idx][amount];
    }

    int notPick = coinChangeHelper(coins, idx - 1, amount, dp);

    int pick = INT_MAX;
    if (coins[idx] <= amount) {
      pick = 1 + coinChangeHelper(coins, idx, amount - coins[idx], dp);
    }

    return dp[idx][amount] = min(pick, notPick);
  }

public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = coinChangeHelper(coins, n - 1, amount, dp);
    if (ans >= 1e9) {
      return -1;
    }

    return ans;
  }
};

int main() {}
