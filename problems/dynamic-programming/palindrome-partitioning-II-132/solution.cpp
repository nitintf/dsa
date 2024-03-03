#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

// TC - O(n^2) - n states are changing and loop for n are running inside those states
//  SC - O(n) / O(n) + O(n)
class Solution {
  bool isPal(string& s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }

    return true;
  }

  int findMinCut(string& s, int i, int n, vector<int>& dp) {
    if (i >= n or isPal(s, i, n))
      return 0;

    if (dp[i] != -1) {
      return dp[i];
    }

    int mini = INT_MAX;
    for (int ind = i; ind < n; ind++) {
      if (isPal(s, i, ind)) {
        int cuts = 1 + findMinCut(s, ind + 1, n, dp);
        mini = min(mini, cuts);
      }
    }

    return dp[i] = mini;
  }

public:
  int minCut(string s) {
    int n = s.length();
    vector<int> dp(n + 1, -1);

    return findMinCut(s, 0, n - 1, dp);
  }

  int minCutTabulation(string s) {
    int n = s.size();
    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; i--) {
      int mini = INT_MAX;
      for (int ind = i; ind < n; ind++) {
        if (isPal(s, i, ind)) {
          int cuts = 1 + dp[ind + 1];
          mini = min(mini, cuts);
        }
      }

      dp[i] = mini;
    }

    return dp[0] - 1;
  }
};

int main() {}
