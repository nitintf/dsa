#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  bool findTarget(vector<int>& arr, int idx, int target, vector<vector<int>>& dp) {
    if (target == 0) {
      return true;
    }

    if (idx == 0) {
      return arr[0] == target;
    }

    if (dp[idx][target] != -1)
      return dp[idx][target];

    bool notPick = findTarget(arr, idx - 1, target, dp);
    bool pick = false;
    if (target >= arr[idx]) {
      pick = findTarget(arr, idx - 1, target - arr[idx], dp);
    }

    return dp[idx][target] = notPick || pick;
  }

public:
  bool subsetSumToK(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return findTarget(arr, n - 1, target, dp);
  }

  bool subsetSumToKTabulation(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
      for (int target = 1; target <= k; target++) {
        bool notTake = dp[i - 1][target];
        bool take = false;
        if (target >= arr[i]) {
          take = dp[i - 1][target - arr[i]];
        }
        dp[i][target] = take || notTake;
      }
    }

    return dp[n - 1][k];
  }

  bool subsetSumToKSpaceOptimized(vector<int>& arr, int k) {}
};

int main() {}
