#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        // Push opening brackets onto the stack
        stack.push(c);
      }
      else {
        // If stack is empty, return false (no matching opening bracket)
        if (stack.empty())
          return false;

        // Check if the current closing bracket matches the top of the
        // stack
        if ((c == ')' && stack.top() == '(') ||
          (c == ']' && stack.top() == '[') ||
          (c == '}' && stack.top() == '{')) {
          stack.pop(); // Matching pair found, pop from stack
        }
        else {
          return false; // Mismatched brackets
        }
      }
    }
    // If stack is empty, all brackets are matched, otherwise, there are
    // unmatched opening brackets
    return stack.empty();
  }
};

int main() {}
