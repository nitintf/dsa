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
  vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    stack<int> st;
    vector<int> ngt(n, 0);

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && temp[st.top()] <= temp[i]) {
        st.pop();
      }

      if (!st.empty()) {
        ngt[i] = st.top() - i;
      }

      st.push(i);
    }

    return ngt;
  }
};

int main() {}
