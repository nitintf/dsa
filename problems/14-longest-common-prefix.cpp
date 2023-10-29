#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  if (strs.empty()) {
    return ""; // If the input vector is empty, return an empty string.
  }

  sort(strs.begin(), strs.end());
  // Sort the strings array and find the minimum length using first element (to avoid out-of-bounds errors)
  int minLen = strs[0].length();
  string prefix = "";

  // Compare characters at the same position in all strings
  for (int i = 0; i < minLen; ++i) {
    char currentChar = strs[0][i]; // Get the character from the first string

    // Check if this character is common across all strings
    for (auto& str : strs) {
      if (str[i] != currentChar) {
        return prefix; // Return the common prefix found so far
      }
    }

    // If the character is common, add it to the prefix
    prefix += currentChar;
  }

  return prefix;
}

int main() {
  // Test cases
  vector<vector<string>> testCases = {
    {"flower", "flow", "flight"},
    {"dog", "racecar", "car"},
    {},
    {"apple"},
    {"abc", "abc", "abc"},
    {"abc", "", "def"},
    {"abcd", "abc", "ab"}
  };

  for (vector<string>& testCase : testCases) {
    string result = longestCommonPrefix(testCase);
    cout << "Input: [";
    for (const auto& str : testCase) {
      cout << "\"" << str << "\", ";
    }
    cout << "]\n";
    cout << "Output: " << result << "\n";
    cout << "------------------------\n";
  }

  return 0;
}
