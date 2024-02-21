#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Solution {
  int findMaxProfit(vector<int>& prices, int idx, int canBuy,
    vector<vector<vector<int>>>& dp, int tran) {
    if (idx == prices.size() || tran == 0) {
      return 0;
    }

    if (dp[idx][canBuy][tran] != -1) {
      return dp[idx][canBuy][tran];
    }

    int profit = 0;

    if (canBuy) {
      // Buying
      int take =
        -prices[idx] + findMaxProfit(prices, idx + 1, 0, dp, tran);
      int notTake = findMaxProfit(prices, idx + 1, 1, dp, tran);

      profit = max(take, notTake);
    }
    else {
      // Selling
      int take =
        prices[idx] + findMaxProfit(prices, idx + 1, 1, dp, tran - 1);
      int notTake = findMaxProfit(prices, idx + 1, 0, dp, tran);

      profit = max(take, notTake);
    }

    return dp[idx][canBuy][tran] = profit;
  }

public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return findMaxProfit(prices, 0, 1, dp, k);
  }

  int maxProfitTabulation(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int idx = n - 1; idx >= 0; idx--) {
      for (int canBuy = 0; canBuy < 2; canBuy++) {
        for (int tran = 1; tran < k + 1; tran++) {

          int profit = 0;

          if (canBuy) {
            // Buying
            int take = -prices[idx] + dp[idx + 1][0][tran];
            int notTake = dp[idx + 1][1][tran];

            profit = max(take, notTake);
          }
          else {
            // Selling
            int take = prices[idx] + dp[idx + 1][1][tran - 1];
            int notTake = dp[idx + 1][0][tran];

            profit = max(take, notTake);
          }

          dp[idx][canBuy][tran] = profit;
        }
      }
    }

    return dp[0][1][k];
  }
};

int main() {}
