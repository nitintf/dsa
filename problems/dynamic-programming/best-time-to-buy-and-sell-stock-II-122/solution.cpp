#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
 [ Recurrence ]
  - Express everything in terms of index (idx, canBuyNextStock)
  - Explore possiblities on that day
  - take the max of all profits made
  - base case
*/

class Solution {
  int findMaxProfit(vector<int>& prices, int idx, int canBuy, vector<vector<int>>& dp) {
    if (idx == prices.size()) {
      return 0;
    }

    if (dp[idx][canBuy] != -1) {
      return dp[idx][canBuy];
    }

    int profit = 0;

    if (canBuy) {
      // Buying
      int take = -prices[idx] + findMaxProfit(prices, idx + 1, 0, dp);
      int notTake = findMaxProfit(prices, idx + 1, 1, dp);

      profit = max(take, notTake);
    }
    else {
      // Selling
      int take = prices[idx] + findMaxProfit(prices, idx + 1, 1, dp);
      int notTake = findMaxProfit(prices, idx + 1, 0, dp);

      profit = max(take, notTake);
    }

    return dp[idx][canBuy] = profit;
  }


public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return findMaxProfit(prices, 0, 1, dp);
  }

  /**
   [ Tabulation ]
    - base case
    - start the loops
    - copy recurrence
  */
  int maxProfitTabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
      for (int canBuy = 0; canBuy < 2; canBuy++) {
        int profit = 0;

        if (canBuy) {
          // Buying
          int take = -prices[idx] + dp[idx + 1][0];
          int notTake = dp[idx + 1][1];

          profit = max(take, notTake);
        }
        else {
          // Selling
          int take = prices[idx] + dp[idx + 1][1];
          int notTake = dp[idx + 1][0];

          profit = max(take, notTake);
        }

        dp[idx][canBuy] = profit;
      }
    }

    return dp[0][1];
  }


  /*
  [ Space optimized ]
    -
  */
  int maxProfitSpaceOptimized(vector<int>& prices) {
    int n = prices.size();
    vector<int> next(2, 0), curr(2, 0);

    for (int idx = n - 1; idx >= 0; idx--) {
      for (int canBuy = 0; canBuy < 2; canBuy++) {
        int profit = 0;

        if (canBuy) {
          // Buying
          int take = -prices[idx] + next[0];
          int notTake = next[1];

          profit = max(take, notTake);
        }
        else {
          // Selling
          int take = prices[idx] + next[1];
          int notTake = next[0];

          profit = max(take, notTake);
        }

        curr[canBuy] = profit;
      }

      next = curr;
    }

    return next[1];
  }
};

int main() {}
