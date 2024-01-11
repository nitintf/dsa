#include<vector>
#include<iostream>
#include<string>

using namespace std;


void generateParenthesisHelper(string curr, int open, int close, vector<string>& result) {
  if (open == 0 && close == 0) {
    result.push_back(curr);
    return;
  }

  if (open > 0) {
    generateParenthesisHelper(curr + '(', open - 1, close, result);
  }

  if (close > open) {
    generateParenthesisHelper(curr + ')', open, close - 1, result);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  generateParenthesisHelper("", n, n, result);
  return result;
}

int main() {}
