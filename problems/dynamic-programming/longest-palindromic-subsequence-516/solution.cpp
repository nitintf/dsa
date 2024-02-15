#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int longestCommonSubSeq(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1;i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        int ans = 0;
        if (s1[i] == s2[j]) {
          ans = 1 + dp[i - 1][j - 1];
        }
        else {
          ans = max(dp[i - 1][j], dp[i][j - 1]);
        }

        dp[i][j] = ans;
      }
    }

    return dp[n][m];
  }

public:
  int longestPalindromeSubseq(string s) {
    string s2 = s;
    reverse(s.begin(), s.end());

    return longestCommonSubSeq(s, s2);
  }

  int longestPalindromeSubseqOptimizedDP(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = 1;
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
        else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main() {}
