#include<vector>
#include<iostream>
#include<string>
#include "stack"

using namespace std;

/**
Notes
*/


bool isOperand(char x) {
  if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) {
    return true;
  }

  return false;
}

string postfixToPrefix(string &s){
    stack<string> st;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (isOperand(ch)) {
            st.push(string(1, ch));
        } else {
            string s1 = st.top();
            st.pop();

            string s2 = st.top();
            st.pop();

            string temp = ch + s2 + s1;
            st.push(temp);
        }
    }

    return st.top();
}

int main() {}
