#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

// https://www.codingninjas.com/studio/problems/boolean-evaluation_1214650
// https://leetcode.com/problems/parsing-a-boolean-expression/
class Solution {
  bool parseBool(string exp, int i, int j) {}

  int evaluateExpHelper(string exp, int i, int j, int isTrue) {
    if (i > j) return 0;

    if (i == j) {
      if (isTrue == 1) {
        return exp[i] == 'T';
      }
      else {
        return exp[i] == 'F';
      }
    }

    int ways = 0;

    for (int ind = i + 1; ind < j - 1; ind += 2) {
      int lt = evaluateExpHelper(exp, i, ind - 1, 1);
      int lf = evaluateExpHelper(exp, i, ind - 1, 0);
      int rt = evaluateExpHelper(exp, ind + 1, j, 1);
      int rf = evaluateExpHelper(exp, ind + 1, j, 0);

      if (exp[ind] == '&') {
        if (isTrue) {
        }
      }
      else if (exp[ind] == '|') {

      }
      else {

      }

    }
  }

public:
  bool parseBoolExpr(string expression) {
    int n = expression.size();

  }

  int evaluateExp(string exp) {

  }
};

int main() {}
