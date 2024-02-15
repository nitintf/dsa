#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int longestPalindromeSubseqOptimizedDP(string s, int n) {
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

public:
  int minInsertions(string s) {
    int n = s.length();
    return n - longestPalindromeSubseqOptimizedDP(s, n);
  }
};

int main() {}
