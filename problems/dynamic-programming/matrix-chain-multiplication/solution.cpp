#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes

[Partition DP]
  - Start with entire block or array: f(i, j) i = start, j = end
  - Try all partitions (loop to try all)
  - Return the best possible 2 partitions
*/

class Solution {
  int minOperations(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
    if (start == end) {
      return 0;
    }

    if (dp[start][end] != -1) {
      return dp[start][end];
    }

    int mini = INT_MAX;
    for (int i = start; i <= end - 1; i++) {
      int steps = (nums[start - 1] * nums[i] * nums[end]) + minOperations(nums, start, i, dp) + minOperations(nums, i + 1, end, dp);
      mini = min(mini, steps);
    }

    return dp[start][end] = mini;
  }

public:
  int matrixChainMultiplication(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minOperations(nums, 1, n - 1, dp);
  }
};

int main() {}
