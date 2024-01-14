#include<vector>
#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

void subseqsHelper(string& s, int idx, string current, unordered_set<string>& subseqs) {
  if (idx == s.size()) {
    subseqs.insert(current);
    return;
  }

  subseqsHelper(s, idx + 1, current + s[idx], subseqs);
  subseqsHelper(s, idx + 1, current, subseqs);
}

string moreSubsequences(int n, int m, string a, string b) {
  if (n == 0) return b;
  if (m == 0) return a;

  unordered_set<string> subseqsOfA;
  unordered_set<string> subseqsOfB;

  subseqsHelper(a, 0, "", subseqsOfA);
  subseqsHelper(b, 0, "", subseqsOfB);

  if (subseqsOfA.size() >= subseqsOfB.size()) {
    return a;
  }
  else {
    return b;
  }
}

int main() {
  string a = "ab", b = "eeg";
  cout << moreSubsequences(a.size(), b.size(), a, b) << endl;
  return 0;
}
