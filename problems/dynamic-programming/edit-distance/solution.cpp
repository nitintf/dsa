#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes

Match strings
  - insert of the same char
  - delete and try finding somewhere else
  - replace and match
*/

class Solution {
  int findDis(string s1, string s2, int idx1, int idx2,
    vector<vector<int>>& dp) {
    if (idx2 < 0)
      return idx1 + 1;
    if (idx1 < 0)
      return idx2 + 1;

    if (dp[idx1][idx2] != -1) {
      return dp[idx1][idx2];
    }

    if (s1[idx1] == s2[idx2]) {
      return 0 + findDis(s1, s2, idx1 - 1, idx2 - 1, dp);
    }

    int insert = findDis(s1, s2, idx1, idx2 - 1, dp);
    int del = findDis(s1, s2, idx1 - 1, idx2, dp);
    int replace = findDis(s1, s2, idx1 - 1, idx2 - 1, dp);

    return dp[idx1][idx2] = 1 + min(insert, min(del, replace));
  }

public:
  int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return findDis(s1, s2, n - 1, m - 1, dp);
  }

  int minDistanceTabulation(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 0 + dp[i - 1][j - 1];
        }
        else {
          int insert = dp[i][j - 1];
          int del = dp[i - 1][j];
          int replace = dp[i - 1][j - 1];

          dp[i][j] = 1 + min(insert, min(del, replace));
        }
      }
    }

    return dp[n][m];
  }
};

int main() {}
