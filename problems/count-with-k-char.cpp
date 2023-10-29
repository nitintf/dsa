#include <string>
#include <map>
#include <iostream>

using namespace std;

int countSubStringsBF(string str, int k) {
  int count = 0;
  int strSize = str.length();

  for (int i = 0; i < strSize; i++) {
    for (int j = i + 1; j < strSize + 1; j++) {
      string sub = str.substr(i, j - i);

      // Map for counting distinct char
      map<char, int> charCount;

      for (int m = 0; m < sub.length(); m++) {
        if (charCount.find(sub[m]) != charCount.end()) {
          charCount[sub[m]]++;
        }
        else {
          charCount[sub[m]] = 1;
        }
      }

      if (charCount.size() == k) {
        count++;
      }
    }

  }
  return count;
}

int countSubStringsBetterBF(string str, int k) {
  int result = 0;
  vector<int> charCount(26, 0);

  for (int i = 0; i < str.length(); i++) {
    int distinctChars = 0;
    fill(charCount.begin(), charCount.end(), 0);
    for (int j = i; j < str.length(); j++) {
      if (charCount[str[j] - 'a'] == 0) {
        distinctChars++;
      }

      charCount[str[j] - 'a']++;

      if (distinctChars == k) {
        result++;
      }
    }

  }
  return result;
}

int main() {
  // Test case 1: String with no substrings having k distinct characters
  string str1 = "abcad";
  int k1 = 2;
  int result1 = countSubStringsBetterBF(str1, k1);
  cout << "Test case 1: " << result1 << endl; // Expected output: 0

  // Test case 2: String with one substring having k distinct characters
  string str2 = "aacfssa";
  int k2 = 3;
  int result2 = countSubStringsBetterBF(str2, k2);
  cout << "Test case 2: " << result2 << endl; // Expected output: 1

  // Test case 3: String with multiple substrings having k distinct characters
  string str3 = "qffds";
  int k3 = 4;
  int result3 = countSubStringsBetterBF(str3, k3);
  cout << "Test case 3: " << result3 << endl; // Expected output: 6

  return 0;
}
