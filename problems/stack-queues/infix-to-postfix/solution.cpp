#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

// TC: O(N), SC: O(N)
class Solution {
  int prec(char c) {
    if (c == '^')
      return 3;
    else if (c == '/' || c == '*')
      return 2;
    else if (c == '+' || c == '-')
      return 1;
    else
      return -1;
  }
public:
  string infixToPostfix(string exp) {
    stack<char> st;
    string output;

    for (char& ch : exp) {
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        output += ch;
      }
      else if (ch == '(') {
        st.push('(');
      }
      else if (ch == ')') {
        while (st.top() != '(') {
          output += st.top();
          st.pop();
        }
        st.pop();
      }
      else {
        while (!st.empty() && prec(ch) <= prec(st.top())) {
          output += st.top();
          st.pop();
        }
        st.push(ch);
      }
    }

    while (!st.empty()) {
      output += st.top();
      st.pop();
    }

    return output;
  }
};

int main() {}
