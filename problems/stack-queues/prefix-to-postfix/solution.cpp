#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

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

bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
  case '%':
    return true;
  }
  return false;
}

bool isOperand(char x) {
  if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) {
    return true;
  }

  return false;
}

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

string prefixToInfix(string& s) {
  int n = s.size();
  stack<string> st;
  for (int i = n - 1; i >= 0; i--) {
    if (isOperator(s[i])) {

      string op1 = st.top();
      st.pop();
      string op2 = st.top();
      st.pop();

      string temp = "(" + op1 + s[i] + op2 + ")";

      st.push(temp);
    }
    else {
      st.push(string(1, s[i]));
    }
  }
  return st.top();
}

// Bad Solution (Brute Force)
// O(2N)
string preToPost(string s) {
  string infix = prefixToInfix(s);

  string output = infixToPostfix(infix);

  return output;
}

// Optimized Solutin
// O(N)
string preToPost(string s) {
  string ans;
  stack<string> st;

  int n = s.size();

  for (int i = n - 1; i >= 0; i--) {
    char ch = s[i];

    if (ch >= 'A' && ch <= 'Z') {
      st.push(string(1, ch));
    }
    else {
      string s1 = st.top();
      st.pop();

      string s2 = st.top();
      st.pop();

      string temp = s1 + s2 + ch;
      st.push(temp);
    }
  }

  return ans;
}

int main() {}
