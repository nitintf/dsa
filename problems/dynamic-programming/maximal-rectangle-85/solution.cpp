#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

class Solution {

  int findMaxArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int largestArea = 0;

    for (int i = 0; i <= n; i++) {
      while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
        int h = heights[st.top()];
        st.pop();
        int w;

        if (st.empty())
          w = i;
        else
          w = i - st.top() - 1;

        largestArea = max(largestArea, w * h);
      }

      st.push(i);
    }
    return largestArea;
  }

public:
  int maximalRectangle(vector<vector<char>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> histogram(m);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') histogram[j]++;
        else histogram[j] = 0;
      }

      maxArea = max(maxArea, findMaxArea(histogram));
    }

    return maxArea;
  }
};

int main() {}
