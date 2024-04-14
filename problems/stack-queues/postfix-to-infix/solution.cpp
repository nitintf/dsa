#include<vector>
#include<iostream>
#include<string>
#include "stack"

using namespace std;

/**
Notes
*/

bool isOperand(char ch) {
  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '1' && ch <= '9')) {
    return true;
  }
  return false;
}

string postToInfix(string postfix) {
  stack<string> st;

  int n = postfix.size();

  for (int i = 0; i < n; i++) {
    char ch = postfix[i];

    if (isOperand(ch)) {
      st.push(string(1, ch));
    }
    else {
      string op1 = st.top();
      st.pop();

      string op2 = st.top();
      st.pop();

      string temp = '(' + op2 + ch + op1 + ')';
      st.push(temp);
    }

  }

  return st.top();
}

int main() {}
