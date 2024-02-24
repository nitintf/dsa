#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

bool compareByLengthAscending(string& a, string& b) {
  return a.length() < b.length();
}

class Solution {
  bool isPredecessor(string a, string b) {
    int n = a.size(), m = b.size();

    if (n != m + 1) {
      return false;
    }

    int i = 0;
    int j = 0;

    while (i < n) {
      if (a[i] == b[j]) {
        i++;
        j++;
      }
      else {
        i++;
      }
    }

    if (i == n && j == m) return true;
    return false;
  }

  bool isPredecessorOpt(const string& word1, const string& word2) {
    if (word1.size() + 1 != word2.size()) return false;

    int i = 0, j = 0;
    bool foundDifference = false;
    while (i < word1.size() && j < word2.size()) {
      if (word1[i] != word2[j]) {
        if (foundDifference) return false;
        foundDifference = true;
        ++j;
      }
      else {
        ++i;
        ++j;
      }
    }

    return true;
  }

public:
  int longestStrChain(vector<string>& words) {
    int n = words.size();

    vector<int> dp(n, 1);

    sort(words.begin(), words.end(), compareByLengthAscending);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (isPredecessorOpt(words[j], words[i]) && dp[j] + 1 > dp[i]) {
          dp[i] = 1 + dp[j];
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};

int main() {}
