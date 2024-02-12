#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int coinChangeHelper(vector<int>& coins, int idx, int amount, vector<vector<long>>& dp) {
    if (idx == 0) {
      return (amount % coins[0] == 0);
    }

    if (dp[idx][amount] != -1) {
      return dp[idx][amount];
    }

    int notPick = coinChangeHelper(coins, idx - 1, amount, dp);

    int pick = 0;
    if (coins[idx] <= amount) {
      pick = coinChangeHelper(coins, idx, amount - coins[idx], dp);
    }

    return dp[idx][amount] = pick + notPick;
  }

public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<long>> dp(n, vector<long>(amount + 1, -1));

    int ans = coinChangeHelper(coins, n - 1, amount, dp);
    // if (ans >= 1e9) {
    // return -1;
    // }

    return ans;
  }
};

int main() {}
