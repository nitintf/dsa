#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
* Different method for comparing
 - trying all ways
 - Recursion
Index represents basically for string j from (0 to m) find sub seq in string a from (0 to i)


2. Tabulation
  - write down the base cases
  - i, j
  - copy paste
*/

const int prime = 1e9 + 7;

class Solution {
  int countWays(string a, string b, int idx1, int idx2, vector<vector<int>>& dp) {
    if (idx2 < 0) {
      return 1;
    }
    if (idx1 < idx2) {
      return 0;
    }

    if (dp[idx1][idx2] != -1) {
      return dp[idx1][idx2];
    }

    if (a[idx1] == b[idx2]) {
      return dp[idx1][idx2] = countWays(a, b, idx1 - 1, idx2 - 1, dp) + countWays(a, b, idx1 - 1, idx2, dp);
    }
    else {
      return dp[idx1][idx2] = countWays(a, b, idx1 - 1, idx2, dp);
    }

  }

  int distinctSubseq(string a, string b) {
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return countWays(a, b, n - 1, m - 1, dp);
  }

  int distinctSubseqTabulation(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= m; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
        }
        else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][m];
  }

  int distinctSubseqSpace(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    prev[0] = curr[0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1]) {
          curr[j] = (prev[j - 1] + prev[j]) % prime;
        }
        else {
          curr[j] = prev[j];
        }
      }
      prev = curr;
    }

    return prev[m];
  }
};

int main() {}
