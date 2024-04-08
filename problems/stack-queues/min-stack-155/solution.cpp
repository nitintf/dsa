#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

// TC: O(1), SC: O(2N)
class MinStack {
  stack<pair<int, int>> st;
public:
  MinStack() {}

  void push(int val) {
    int mini;
    if (st.empty()) {
      mini = val;
    }
    else {
      mini = min(st.top().second, val);
    }
    st.push({ val, mini });
  }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

// TC: O(1), SC: O(N)
// push = 2 x val - mini
// mini = (2 x mini) - (push)
// convert it into long
class MinStack {
  stack<long long> st;
  long long mini;

public:
  MinStack() {
    while (st.empty() == false) st.pop();
    mini = INT_MAX;
  }

  void push(int val) {
    long long value = val;
    if (st.empty()) {
      mini = value;
      st.push(value);
    }
    else {
      if (value < mini) {
        st.push(2 * value * 1LL - mini);
        mini = value;
      }
      else {
        st.push(value);
      }
    }
  }

  void pop() {
    if (st.empty()) return;

    long long topEl = st.top();
    st.pop();

    if (topEl < mini) {
      int newMin = 2 * mini - topEl;
      mini = newMin;
    }
  }

  int top() {
    if (st.empty()) return -1;
    long long el = st.top();

    if (el < mini) {
      return mini;
    }

    return el;
  }

  int getMin() { return mini; }
};
;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {}
