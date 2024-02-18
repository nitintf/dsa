#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  string shortestCommonSubSeq(string a, string b) {
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    string result = "";

    int k = n;
    int l = m;

    while (k > 0 && l > 0) {
      if (a[k - 1] == b[l - 1]) {
        result += a[k - 1];
        k--;
        l--;
      }
      else if (dp[k - 1][l] > dp[k][l - 1]) {
        result += a[k - 1];
        k--;
      }
      else {
        result += b[l - 1];
        l--;
      }
    }

    while (k > 0) {
      result += a[k - 1];
      k--;
    }

    while (l > 0) {
      result += b[l - 1];
      l--;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {}
