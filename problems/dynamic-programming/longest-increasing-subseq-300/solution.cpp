#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/


class Solution {
  int findLIS(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
    if (idx == nums.size()) {
      return 0;
    }

    if (dp[idx][prevIdx] != -1) {
      return dp[idx][prevIdx];
    }

    int len = findLIS(nums, idx + 1, prevIdx, dp);
    if (prevIdx == -1 || nums[prevIdx] < nums[idx]) {
      len = max(len, 1 + findLIS(nums, idx + 1, idx, dp));
    }

    return dp[idx][prevIdx + 1] = len;
  }

public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return findLIS(nums, 0, -1, dp);
  }

  int lengthOfLISTabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
      for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--) {
        int len = dp[idx + 1][prev_idx + 1];
        if (prev_idx == -1 || nums[prev_idx] < nums[idx]) {
          len = max(len, 1 + dp[idx + 1][idx + 11]);
        }

        dp[idx][prev_idx + 1] = len;
      }
    }

    return dp[0][0];
  }

  int lengthOfLISSpaceOptimized(vector<int>& nums) {
    int n = nums.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--) {
      for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--) {
        int len = next[prev_idx + 1];
        if (prev_idx == -1 || nums[prev_idx] < nums[idx]) {
          len = max(len, 1 + next[idx + 11]);
        }

        curr[prev_idx + 1] = len;
      }

      next = curr;
    }

    return curr[0];
  }

  int lengthOfLISSpaceOpt(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
          dp[i] = dp[j] + 1;
    return *max_element(dp.begin(), dp.end());
  }

  vector<int> printLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);

    int maxi = 1, lastIndex = 0;

    for (int i = 0; i < n; ++i) {
      hash[i] = i;
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          hash[i] = j;
        }
      }

      if (dp[i] > maxi) {
        maxi = dp[i];
        lastIndex = i;
      }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex) {
      lastIndex = hash[lastIndex];
      temp.push_back(nums[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
  }

  int lengthOfLISBinarySearch(vector<int>& nums) {}
};

int main() {}
