#include<vector>
#include<iostream>
#include<string>

using namespace std;

void generateBinaryString(string curr, int n, vector<string>& result) {

  if (curr.length() == n) {
    result.push_back(curr);
    return;
  }

  if (!curr.empty() && curr.back() == '1') {
    generateBinaryString(curr + '0', n, result);
  }
  else {
    generateBinaryString(curr + '0', n, result);
    generateBinaryString(curr + '1', n, result);
  }
}

vector<string> generateString(int N) {
  vector<string> result;
  generateBinaryString("", N, result);
  return result;
}

int main() {}
