#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  int robHelper(vector<int>& dp, int index, vector<int>& nums) {
    if (index < 0) {
      return 0;
    }

    if (index == 0) {
      return nums[0];
    }

    if (dp[index] != -1) {
      return dp[index];
    }

    int pick = nums[index] + robHelper(dp, index - 2, nums);
    int skip = robHelper(dp, index - 1, nums);

    return dp[index] = max(pick, skip);
  }

  // Memoization worst case O(2^n)
  int rob(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, -1);
    int n = nums.size();
    return robHelper(dp, n - 1, nums);
  }

  // Tabulation O(n), O(n)
  int robTabulation(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, -1);

    dp[0] = nums[0];

    for (int i = 1; i < n;i++) {
      int pick = nums[i];
      if (i - 2 >= 0) {
        pick += dp[i - 2];
      }
      int skip = dp[i - 1];
      dp[i] = max(pick, skip);
    }

    return dp[n - 1];
  }

  // Space optimized O(n), O(1)
  int robSpaceOptimized(vector<int>& nums) {
    int n = nums.size();
    int prev = 0;
    int curr = nums[0];

    for (int i = 1; i < n;i++) {
      int pick = nums[i];
      if (i - 2 >= 0) {
        pick += prev;
      }
      int skip = curr;
      prev = curr;
      curr = max(pick, skip);
    }

    return curr;
  }
};

int main() {
  Solution sol;
  vector<int> nums = { 1, 2, 3, 1 };
  cout << sol.rob(nums) << endl;
  return 0;
}
