#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += nums[i];
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }

    if (nums[0] <= totalSum) {
      dp[0][totalSum] = true;
    }

    for (int ind = 1; ind < n; ind++) {
      for (int tar = 1; tar <= totalSum; tar++) {
        bool notPick = dp[ind - 1][tar];
        bool pick = false;
        if (tar >= nums[ind]) {
          pick = dp[ind - 1][tar - nums[ind]];
        }

        dp[ind][tar] = pick || notPick;
      }
    }

    int mini = 1e9;

    for (int i = 0; i <= totalSum; i++) {
      if (dp[n - 1][i] == true) {
        int diff = abs(i - (totalSum - i));
        mini = min(mini, diff);
      }
    }

    return mini;
  }
};

int main() {}
