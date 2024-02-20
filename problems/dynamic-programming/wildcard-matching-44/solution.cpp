#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/


class Solution {
  bool findMatch(string s, string p, int i, int j, vector<vector<int>>& dp) {

    if (i < 0 && j < 0) {
      return true;
    }

    if (j < 0 && i >= 0) {
      return false;
    }

    if (i < 0 && j >= 0) {
      for (int k = 0; k <= j; k++) {
        if (p[k] != '*') return false;
      }
      return true;
    }

    if (dp[i][j] != -1) {
      return dp[i][j];
    }


    if (s[i] == p[j] || p[j] == '?') {
      return dp[i][j] = findMatch(s, p, i - 1, j - 1, dp);
    }

    if (p[j] == '*') {
      bool notMatchStar = findMatch(s, p, i - 1, j, dp);
      bool matchStar = findMatch(s, p, i, j - 1, dp);

      return dp[i][j] = notMatchStar || matchStar;
    }

    return false;
  }

public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return findMatch(s, p, n - 1, m - 1, dp);

  }

  bool isMatchTabulation(string s, string p) {
    int m = s.size();
    int n = p.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

    dp[0][0] = true;
    for (int j = 1; j <= m; j++) dp[0][j] = true;

    for (int i = 1; i <= n; i++) {
      int flag = true;
      for (int k = 1; k <= i; k++) {
        if (p[k - 1] != '*') {
          flag = false;
          break;
        }
      }
      dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else if (p[i - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
        else {
          dp[i][j] = false;
        }
      }
    }

    return dp[n][m];
  }


  bool isMatchTabulationBetter(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    if (p[0] == '*') dp[0][1] = true;
    for (int j = 2; j <= m; j++) {
      if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else {
          if (p[j - 1] == '*') {
            dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
          }
        }
      }
    }

    return dp[n][m];
  }
};

int main() {}
