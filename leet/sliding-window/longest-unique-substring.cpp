#include <string>
#include <iostream>

using namespace std;

int longestUniqueSubString(string s) {
  int longest = 0;
  int start = 0;
  unordered_map<char, int> window;

  for (int end = 0; end < s.length(); end++) {
    char ch = s[end];

    if (window.find(ch) != window.end() && window[ch] >= start) {
      // If the character is already in the current window, and its index is greater
      // than or equal to the current start, update the start to the next character.
      start = window[ch] + 1;
    }

    window[ch] = end;
    longest = max(longest, end - start + 1);
  }
  return longest;
}

int longestUniqueSubsttr(string str) {
  int n = str.size();
  int maxLen = 0;
  int left = 0;
  int freq[26];
  for (int i = 0; i < 26; i++)
    freq[i] = -1;

  for (int right = 0; right < n; right++)
  {
    if (freq[str[right] - 'a'] > -1 && left <= freq[str[right] - 'a'])
      left = freq[str[right] - 'a'] + 1; // go last visit index

    freq[str[right] - 'a'] = right;
    maxLen = max(maxLen, right - left + 1);
  }

  return maxLen;
}


int main() {

  string s = "geeksforgeeks";
  int output = longestUniqueSubString(s);

  cout << output << endl;

  return 0;
}
