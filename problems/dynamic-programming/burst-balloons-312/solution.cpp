#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Solution {
  int maxCoinsHelper(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
    // base case
    if (i > j) return 0;

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int maxi = INT_MIN;
    for (int k = i; k <= j; k++) {
      int coins = nums[i - 1] * nums[k] * nums[j + 1] + maxCoinsHelper(nums, i, k - 1, dp) + maxCoinsHelper(nums, k + 1, j, dp);
      maxi = max(maxi, coins);
    }

    return dp[i][j] = maxi;
  }
public:
  // TC - O(n^3)
  // SC - O(n^2) + O(n)
  int maxCoins(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    return maxCoinsHelper(nums, 1, n, dp);
  }

  // TC - O(n^3)
  // SC - O(n^2)
  int maxCoinsTabulation(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= n; j++) {
        if (i > j) continue;

        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {
          int coins = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
          maxi = max(maxi, coins);
        }
        dp[i][j] = maxi;
      }
    }

    return dp[1][n];
  }
};

int main() {}
