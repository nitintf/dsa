#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {

  // O(n^2)
  auto expandFromCenter(int left, int right, string s) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }
    return s.substr(left + 1, right - left - 1);
  }

public:
  string longestPalindrome(string s) {
    if (s.length() <= 1) {
      return s;
    }

    string max_str = s.substr(0, 1);

    for (int i = 0; i < s.length() - 1; i++) {
      string odd = expandFromCenter(i, i, s);
      string even = expandFromCenter(i, i + 1, s);

      if (odd.length() > max_str.length()) {
        max_str = odd;
      }

      if (even.length() > max_str.length()) {
        max_str = even;
      }
    }

    return max_str;
  }

  string longestPalindromeDP(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Base cases: single characters and adjacent characters
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
      if (i < n - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
      }
    }

    // Fill the table iteratively
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1;
        dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
      }
    }

    // Find the longest palindrome
    int max_len = 0, start = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (dp[i][j] && j - i + 1 > max_len) {
          max_len = j - i + 1;
          start = i;
        }
      }
    }

    return s.substr(start, max_len);
  }

  // O(n^2)
  string longestPalin(string s) {
    // Initialize variables to keep track of the 
    // longest palindrome and its length.
    int count = -1;
    string ans = "";

    // Get the length of the input string.
    int n = s.length();

    // Create a boolean 2D array to store palindrome information.
    bool dp[n][n];

    // Iterate through different substring lengths.
    for (int g = 0; g < n; g++) {
      for (int i = 0, j = g; j < n; i++, j++) {
        // Check if the substring is of length 1 (base case).
        if (g == 0) {
          dp[i][j] = true;
        }
        else if (g == 1) {
          // Check if the substring is of length 2 (base case).
          dp[i][j] = (s[i] == s[j]);
        }
        else {
          // Check if the current substring is a 
          // palindrome based on its ends.
          dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }

        // Update the longest palindrome and its length if found.
        if (dp[i][j] && count < j - i + 1) {
          ans = s.substr(i, j - i + 1);
          count = ans.length();
        }
      }
    }
    return ans;
  }
};

int main() {}
