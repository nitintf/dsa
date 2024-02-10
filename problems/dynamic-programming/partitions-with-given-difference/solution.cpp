#include<vector>
#include<iostream>
#include<string>

using namespace std;

int findWaysHelper(vector<int>& arr, int target, int ind, vector<vector<int>>& dp) {
  if (ind == 0) {
    if (target == 0 && arr[0] == 0) {
      return 2;
    }
    if (target == 0 || arr[0] == target) {
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

int findWays(vector<int>& arr, int target) {
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(target + 1, -1));
  return findWaysHelper(arr, target, n - 1, dp);
}

int countPartitions(int n, int d, vector<int>& arr) {
  int totalSum = 0;

  for (auto& num : arr) totalSum += num;

  if (totalSum - d < 0 || (totalSum - d) % 2) {
    return 0;
  }

  return findWays(arr, (totalSum - d) / 2);
}




int main() {}
