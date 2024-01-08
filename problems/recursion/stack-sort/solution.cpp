#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

void insert(stack<int>& s, int current) {
  if (s.empty() || current > s.top()) {
    s.push(current);
    return;
  }

  int top = s.top();
  s.pop();

  insert(s, current);

  s.push(top);
}

void sortStack(stack<int>& s) {
  if (s.empty()) {
    return;
  }

  // remove the top elm
  int top = s.top();
  s.pop();

  sortStack(s);

  insert(s, top);
}


int main() {}
