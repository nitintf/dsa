#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  unordered_map<int, vector<char>> keypadChars = {
      {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}},
      {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
      {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}},
      {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}} };

  void letterCombinationsHelper(string digits, int index, string current,
    vector<string>& result) {
    if (index == digits.size()) {
      if (!current.empty()) {
        result.push_back(current);
      }
      return;
    }

    int digit = digits[index] - '0';

    if (keypadChars.find(digit) != keypadChars.end()) {
      for (char ch : keypadChars[digit]) {
        letterCombinationsHelper(digits, index + 1, current + ch,
          result);
      }
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (!digits.empty()) {
      letterCombinationsHelper(digits, 0, "", result);
    }
    return result;
  }
};

int main() {
  Solution solution;
  vector<string> result = solution.letterCombinations("23");
  for (string s : result) {
    cout << s << endl;
  }
  return 0;
}
