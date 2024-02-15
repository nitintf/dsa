#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int findSubSeq(string a, string b, int idx1, int idx2, vector<vector<int>>& dp) {
    if (idx1 < 0 || idx2 < 0) {
      return 0;
    }

    if (dp[idx1][idx2] != -1) {
      return dp[idx1][idx2];
    }

    if (a[idx1] == b[idx2]) {
      return dp[idx1][idx2] = 1 + findSubSeq(a, b, idx1 - 1, idx2 - 1, dp);
    }

    return dp[idx1][idx2] = max(findSubSeq(a, b, idx1 - 1, idx2, dp), findSubSeq(a, b, idx1, idx2 - 1, dp));
  }

  int longestCommonSubSeqTab(string text1, string text2) {
    int n = max(text1.length(), text2.length());
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = text1.length() - 1; i >= 0; i--) {
      for (int j = text2.length() - 1; j >= 0; j--) {
        int ans = 0;
        if (text1[i] == text2[j]) {
          ans = 1 + dp[i + 1][j + 1];
        }
        else {
          ans = 0 + max(dp[i + 1][j], dp[i][j + 1]);
        }

        dp[i][j] = ans;
      }
    }

    return dp[0][0];
  }

public:
  int longestCommonSubSeq(string a, string b) {
    int n1 = a.length();
    int n2 = b.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    return findSubSeq(a, b, n1 - 1, n2 - 1, dp);
  }
};

int main() {}
