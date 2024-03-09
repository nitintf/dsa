#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

class Solution {

  // Brute Force (TLE)
public:
  int largestRectangleAreaBF(vector<int>& heights) {
    int n = heights.size();

    int largestArea = INT_MIN;

    for (int i = 0; i < n; i++) {
      int left = i + 1;
      int right = i;

      for (int k = i; k >= 0; k--) {
        if (heights[k] >= heights[i]) {
          left--;
        }
        else {
          break;
        }
      }

      for (int k = i; k < n; k++) {
        if (heights[k] >= heights[i]) {
          right++;;
        }
        else {
          break;
        }
      }

      int width = right - left;
      int area = heights[i] * width;
      largestArea = max(largestArea, area);
    }

    return largestArea;
  }

  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int largestArea = 0;

    // the end indicies of ele on the left
    vector<int> leftHalf(n);

    // the end indicies of ele on the right
    vector<int> rightHalf(n, n - 1);

    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
      }

      if (!st.empty())
        leftHalf[i] = st.top() + 1;

      st.push(i);
    }

    while (!st.empty())
      st.pop();

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        st.pop();
      }

      if (!st.empty())
        rightHalf[i] = st.top() - 1;
      largestArea =
        max(largestArea, heights[i] * (rightHalf[i] - leftHalf[i] + 1));
      st.push(i);
    }

    return largestArea;
  }

  int largestRectangleAreaOptimized(vector<int>& heights) {
    int n = heights.size();
    int largestArea = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++) {
      while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
        int h = heights[st.top()];
        st.pop();
        int width;
        if (st.empty()) width = i;
        else width = i - st.top() - 1;
        largestArea = max(largestArea, width * h);
      }
      st.push(i);
    }

    return largestArea;
  }
};


int main() {}
