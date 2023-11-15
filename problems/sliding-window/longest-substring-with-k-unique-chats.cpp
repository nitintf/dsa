#include<string>
#include<iostream>
#include <algorithm> 

using namespace std;

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
