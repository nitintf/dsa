#include<string>
#include<iostream>
#include <algorithm> 

using namespace std;

/**
 * Finds the length of the longest substring in a given string `s` such that every character in the substring appears at least `k` times.
 *
 * @param s the input string
 * @param k the minimum number of times each character should appear in the substring
 *
 * @return the length of the longest substring that satisfies the condition, or -1 if no such substring exists
 *
 * @throws None
 */
int longestSubstring(string s, int k) {
  int n = s.size();

  int left = 0, right = 0;
  unordered_map<char, int>charMap;
  int max_count = 0;

  while (right < n) {
    char c = s[right];
    charMap[c]++;

    if (charMap.size() == k) {
      int max = 0;
      for (auto& ch : charMap) {
        max += ch.second;
      }
      if (max > max_count) {
        max_count = max;
      }
    }
    else if (charMap.size() > k) {
      while (charMap.size() > k) {
        charMap[s[left]]--;
        if (charMap[s[left]] == 0) {
          charMap.erase(s[left]);
        }
        left++;
      }
    }

    right++;

  }

  if (max_count == 0) {
    return -1;
  }

  return max_count;
}


int main() {
  string s = "aabacbebebe";
  int k = 3;
  int ans = longestSubstring(s, k);

  cout << ans << endl;

  return 0;
}
