#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Solution {
  int findMaxProfit(vector<int>& prices, int idx, int canBuy, vector<vector<vector<int>>>& dp, int tran) {
    if (idx == prices.size() || tran == 0) {
      return 0;
    }

    if (dp[idx][canBuy][tran] != -1) {
      return dp[idx][canBuy][tran];
    }

    int profit = 0;

    if (canBuy) {
      // Buying
      int take = -prices[idx] + findMaxProfit(prices, idx + 1, 0, dp, tran);
      int notTake = findMaxProfit(prices, idx + 1, 1, dp, tran);

      profit = max(take, notTake);
    }
    else {
      // Selling
      int take = prices[idx] + findMaxProfit(prices, idx + 1, 1, dp, tran - 1);
      int notTake = findMaxProfit(prices, idx + 1, 0, dp, tran);

      profit = max(take, notTake);
    }

    return dp[idx][canBuy][tran] = profit;
  }


public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return findMaxProfit(prices, 0, 1, dp, 2);
  }

  int maxProfitTabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int idx = n - 1; idx >= 0; idx--) {
      for (int canBuy = 0; canBuy < 2; canBuy++) {
        for (int tran = 1; tran < 3; tran++) {

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

    return dp[0][1][2];
  }

  /*
  (O(N) time O(1) space) [ACCEPTED]
  Suppose you make some profit p1 by doing your first transaction in the stock market. Now you are excited to purchase another stock to earn more profit. Suppose the price of the second stock you aim to buy is x. Now, for you, the net effective price that you are spending from your pocket for this stock will be x-p1, because you already have p1 bucks in your hand. Now, if you sell the second stock at price y your net profit p2 will be p2 = y - (x-p1). You have to do nothing but maximize this profit p2.
  */
  int maxProfitOptimized(vector<int>& prices) {
    if (!prices.size())
      return 0;
    int buy1 = INT_MAX;
    int profit1 = INT_MIN;
    int buy2 = INT_MAX;
    int profit2 = INT_MIN;
    for (int i = 0; i < prices.size(); i++) {
      buy1 = min(buy1, prices[i]);
      profit1 = max(profit1, prices[i] - buy1);
      buy2 = min(buy2, prices[i] - profit1);
      profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
  }
};

int main() {}
