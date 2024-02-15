#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;
    int result = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int ans = 0;
        if (s1[i - 1] == s2[j - 1]) {
          ans = 1 + dp[i - 1][j - 1];
          result = max(ans, result);
        }

        dp[i][j] = ans;
      }
    }

    return result;
  }
};

int main() {}
