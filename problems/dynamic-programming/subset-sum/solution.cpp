#include<vector>
#include<iostream>
#include<string>

using namespace std;

bool isSubsetPresentHelper(vector<int>& a, int sum, int idx, unordered_map<string, bool>& memo) {
  if (sum == 0) {
    return true;
  }

  if (a.size() == idx) {
    return false;
  }

  string key = to_string(idx) + "_" + to_string(sum);

  if (memo.find(key) != memo.end()) {
    return memo[key];
  }

  // Recursive calls
  bool includeCurrent = isSubsetPresentHelper(a, sum - a[idx], idx + 1, memo);
  bool excludeCurrent = isSubsetPresentHelper(a, sum, idx + 1, memo);

  // Memoize the result
  memo[key] = includeCurrent || excludeCurrent;

  return memo[key];
}

bool isSubsetPresentBottomUp(int n, int k, vector<int>& a)
{
  unordered_map<string, bool> memo;
  return isSubsetPresentHelper(a, k, 0, memo);
}

int isSubsetPresentTopDown(int n, int k, vector<int>& a)
{
  vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

  // Empty subset is always possible with sum 0
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      // If the current element is greater than the target sum, exclude it
      if (j < a[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        // Include the current element or exclude it
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
      }
    }
  }

  return dp[n][k];
}

bool isSubsetPresentHelperRecursive(vector<int>& a, int sum, int idx, int k) {
  if (sum == k) {
    return true;
  }
  else if (sum > k || idx >= a.size()) {
    return false;
  }

  return isSubsetPresentHelperRecursive(a, sum + a[idx], idx + 1, k) || isSubsetPresentHelperRecursive(a, sum, idx + 1, k);
}

bool isSubsetPresent(int n, int k, vector<int>& a)
{
  return isSubsetPresentHelperRecursive(a, 0, 0, k);
}

int main() {}
