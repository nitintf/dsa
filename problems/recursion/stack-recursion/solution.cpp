#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

void insert(stack<int>& s, int current) {
  if (s.empty()) {
    s.push(current);
    return;
  }

  int tmp = s.top();
  s.pop();

  insert(s, current);

  s.push(tmp);
}

void reverseStack(stack<int>& s) {
  if (s.empty()) {
    return;
  }

  int tmp = s.top();
  s.pop();

  reverseStack(s);

  insert(s, tmp);
}

int main() {}
