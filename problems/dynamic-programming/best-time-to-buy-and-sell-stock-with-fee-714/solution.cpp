#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/


class Solution {
  int findMaxProfit(vector<int>& prices, int idx, int canBuy,
    vector<vector<int>>& dp, int fee) {
    if (idx >= prices.size()) {
      return 0;
    }

    if (dp[idx][canBuy] != -1) {
      return dp[idx][canBuy];
    }

    int profit = 0;

    if (canBuy) {
      // Buying
      int take =
        -prices[idx] - fee + findMaxProfit(prices, idx + 1, 0, dp, fee);
      int notTake = findMaxProfit(prices, idx + 1, 1, dp, fee);

      profit = max(take, notTake);
    }
    else {
      // Selling
      int take = prices[idx] + findMaxProfit(prices, idx + 1, 1, dp, fee);
      int notTake = findMaxProfit(prices, idx + 1, 0, dp, fee);

      profit = max(take, notTake);
    }

    return dp[idx][canBuy] = profit;
  }

public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return findMaxProfit(prices, 0, 1, dp, fee);
  }
};

int main() {}
