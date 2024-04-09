#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

// TC: O(n), SC: O(n)
class Solution {
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

public:
  string prefixToInfixConversion(string& s) {
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

};

int main() {}
