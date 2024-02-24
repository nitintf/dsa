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

  // @TODO: undestand tabulation
  int lengthOfLISTabulation(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {

      }
    }
  }

  int lengthOfLISBinarySearch(vector<int>& nums) {}
};

int main() {}
