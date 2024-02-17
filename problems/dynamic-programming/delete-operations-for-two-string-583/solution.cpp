#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int findLCS(string a, string b) {
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int ans = 0;
        if (a[i - 1] == b[j - 1]) {
          ans = 1 + dp[i - 1][j - 1];
        }
        else {
          ans = max(dp[i][j - 1], dp[i - 1][j]);
        }

        dp[i][j] = ans;
      }
    }

    return dp[n][m];
  }

public:
  int minDistance(string word1, string word2) {
    int lcs = findLCS(word1, word2);

    int lenOfWords = word1.length() + word2.length();

    return lenOfWords - 2 * lcs;
  }
};

int main() {}
