#include <string>

using namespace std;

int numOfToys(string s, int k) {
  int n = s.size();

  int left = 0, right = 0;

  int max_count = 0;

  unordered_map<char, int>charMap;

  while (right < n) {
    char c = s[right];
    charMap[c]++;

    if (charMap.size() == k) {
      max_count = max(max_count, right - left + 1);
    }
    else if (charMap.size() > k) {
      while (charMap.size() > k)
      {
        charMap[s[left]--];
        if (charMap[s[left]] == 0) {
          charMap.erase(s[left]);
        }
        left++;
      }
    }

    right++;
  }

  return max_count;
}
