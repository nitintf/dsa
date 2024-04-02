#include<vector>
#include<iostream>
#include<string>
#include<queue>

using namespace std;

/**
Notes
TC: O(n)
SC: O(n)
*/

class MyStack {
public:
  queue<int> q;

  void push(int x) {
    int s = q.size();
    q.push(x);

    for (int i = 0; i < s; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int n = q.front();
    q.pop();
    return n;
  }

  int top() {
    return q.front();
  }

  bool empty() {
    return q.empty();
  }

  int size() {
    return q.size();
  }
};

int main() {}
