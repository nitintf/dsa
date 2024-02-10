#include<vector>
#include<iostream>
#include<string>

using namespace std;


class Solution {
  int findWaysHelper(vector<int>& arr, int target, int ind, vector<vector<int>>& dp) {
    if (ind == 0) {
      if (target == 0 && arr[0] == 0) {
        return 2;
      }
      if (target == 0 || arr[ind] == target) {
        return 1;
      }

      return 0;
    }

    if (dp[ind][target] != -1) {
      return dp[ind][target];
    }

    int notPick = findWaysHelper(arr, target, ind - 1, dp);

    int pick = 0;

    if (target >= arr[ind]) {
      pick = findWaysHelper(arr, target - arr[ind], ind - 1, dp);
    }

    return dp[ind][target] = notPick + pick;
  }

public:
  int findWays(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return findWaysHelper(arr, target, n - 1, dp);
  }

  int findWaysTabulation(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }

    if (arr[0] <= target) {
      dp[0][arr[0]] = 1;
    }

    for (int idx = 1; idx < n; idx++) {
      for (int tar = 1; tar < target; tar++) {
        int notPick = dp[idx - 1][tar];
        int pick = 0;
        if (tar >= arr[idx]) {
          pick = dp[idx - 1][tar - arr[idx]];
        }

        dp[idx][tar] = pick + notPick;
      }
    }

    return dp[n - 1][target];
  }
};

int main() {}
