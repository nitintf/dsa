#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TC: O(n)
// SC: O(k)

/*
@see https://leetcode.com/problems/find-all-anagrams-in-a-string/

APPROACH
--------
1. Count occurences of each character in p store in map.
2. Start sliding window of size k.
3. if we find the element in our map dicrease by 1 and check if its 0 then decrease count.
4. if window is lesser than size k then increase i.
5. if window is equal to size k then check if count is 0 then push_back j.
6. the element on position j is in our map so increase its value by 1 and check if its 1 then increase count and increase i and j.
*/

vector<int> countNoOfAnagrams(string s, string p) {
  int k = p.size();
  int n = s.size();

  if (n < k) {
    return {};
  }

  vector<int> res;
  unordered_map<char, int> mp;
  int i = 0, j = 0;

  for (int m = 0; m < k; m++) {
    mp[p[m]]++;
  }

  int count = mp.size();

  while (i < n)
  {
    if (mp.find(s[i]) != mp.end()) {
      mp[s[i]]--;
      if (mp[s[i]] == 0) {
        count--;
      }
    }

    if (i - j + 1 < k) {
      i++;
    }
    else if (i - j + 1 == k) {
      if (count == 0) {
        res.push_back(j);
      }
      if (mp.find(s[j]) != mp.end()) {
        mp[s[j]]++;
        if (mp[s[j]] == 1) {
          count++;
        }
      }

      i++;
      j++;
    }
  }

  return res;
}

// Optimal aproach
// TC: O(n)
// SC: O(1)
vector<int> findAnagrams(string s, string p) {
  int s_len = s.length();
  int p_len = p.length();

  if (s.size() < p.size()) return {};

  vector<int> freq_p(26, 0);
  vector<int> window(26, 0);

  //first window
  for (int i = 0;i < p_len;i++) {
    freq_p[p[i] - 'a']++;
    window[s[i] - 'a']++;
  }

  vector<int> ans;
  if (freq_p == window) ans.push_back(0);

  for (int i = p_len;i < s_len;i++) {
    window[s[i - p_len] - 'a']--;
    window[s[i] - 'a']++;

    if (freq_p == window) ans.push_back(i - p_len + 1);
  }
  return ans;
}

// BRUTE FORCE
// TLE
vector<int> findAnagrams1(string s, string p) {
  int s_len = s.length();
  int p_len = p.length();
  vector<int> result;
  int n = p.length();

  if (s.size() < p.size()) return {};

  for (int i = 0; i < s.length(); i++) {
    string ns = s.substr(i, n);
    if (ns == p) {
      result.push_back(i);
      continue;
    }

    sort(ns.begin(), ns.end());
    sort(p.begin(), p.end());

    if (ns == p) {
      result.push_back(i);
    }
  }

  return result;
}

int main() {
  string s = "cbaebabacd", p = "abc";
  vector<int> res = findAnagrams(s, p);
  return 0;
}
