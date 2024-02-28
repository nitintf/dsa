#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Solution {
  // Memoization
  // 2 chainging var i, j -> c^2  and loop from i to j so final TC O(n^3)
  // SP - O(n^2) + stack space
  int findMinCost(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int mini = 1e9;
    for (int k = i; k <= j; k++) {
      int cost = cuts[j + 1] - cuts[i - 1] + findMinCost(cuts, i, k - 1, dp) + findMinCost(cuts, k + 1, j, dp);
      mini = min(mini, cost);
    }

    return dp[i][j] = mini;
  }

public:
  int minCost(int n, vector<int>& cuts) {
    int m = cuts.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return findMinCost(cuts, 1, m, dp);
  }

  int minCostTabulation(int n, vector<int>& cuts) {
    int m = cuts.size();
    vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    for (int i = m; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        if (i > j) continue;

        int mini = 1e9;
        for (int k = i; k <= j; k++) {
          int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
          mini = min(mini, cost);
        }
        dp[i][j] = mini;
      }
    }

    return dp[1][m];
  }
};

int main() {}
