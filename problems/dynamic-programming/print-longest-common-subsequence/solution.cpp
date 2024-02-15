#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  string printLongestSubSeq(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int ans = 0;
        if (s1[i - 1] == s2[j - 1]) {
          ans = 1 + dp[i - 1][j - 1];
        }
        else {
          ans = 0 + max(dp[i][j - 1], dp[i - 1][j]);
        }

        dp[i][j] = ans;
      }
    }

    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; i++) {
      ans += "$";
    }

    int index = len - 1;
    int i = n, j = m;

    while (i > 0 && j > 0) {
      if (s1[i - 1] == s2[j - 1]) {
        ans[index] = s1[i - 1];
        index--;
        i--, j--;
      }
      else if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
      }
      else {
        j--;
      }
    }

    return ans;
  }
};

int main() {}
