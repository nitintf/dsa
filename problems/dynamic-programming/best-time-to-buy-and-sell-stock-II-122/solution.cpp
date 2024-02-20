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
};

int main() {}
