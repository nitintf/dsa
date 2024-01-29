#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--]) {
        return false;
      }
    }
    return true;
  }

  void partitionHelper(vector<vector<string>>& result, vector<string>& current, int idx, string s) {
    if (idx == s.size()) {
      result.push_back(current);
      return;
    }

    for (int i = idx; i < s.size(); ++i) {
      if (isPalindrome(s, idx, i)) {
        current.push_back(s.substr(idx, i - idx + 1));
        partitionHelper(result, current, i + 1, s);
        current.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(result, current, 0, s);
    return result;
  }
};

int main() {
  Solution solution;
  vector<vector<string>> result = solution.partition("aab");
  for (auto& v : result) {
    for (auto& s : v) {
      cout << s << " ";
    }
    cout << endl;
  }
  return 0;
}
