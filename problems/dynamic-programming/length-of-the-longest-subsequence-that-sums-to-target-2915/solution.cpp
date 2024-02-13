#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int helper(vector<int>& nums, int target, int idx, vector<vector<int>>& dp) {
    if (target == 0) return 0;

    if (idx < 0 && target != 0) return -1e9;

    if (dp[idx][target] != -1) {
      return dp[idx][target];
    }

    int notPick = helper(nums, target, idx - 1, dp);

    int pick = -1e9;
    if (nums[idx] <= target) {
      pick = 1 + helper(nums, target - nums[idx], idx - 1, dp);
    }

    return dp[idx][target] = max(pick, notPick);
  }

public:
  int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int ans = helper(nums, target, n - 1, dp);
    if (ans < 0) {
      return -1;
    }

    return ans;
  }
};

int main() {}
