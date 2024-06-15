#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/**
Notes
*/

class Solution {
private:
  const int MOD = 1e9 + 7;

public:
  // Brute Force approach, TC O(N^2), SC O(1)
  // finding the contiguous subarrays and at the same time finding the mini and
  // adding it to final sum.
  int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      sum = (sum + arr[i]) % MOD;

      int mini = arr[i];

      for (int j = i + 1; j < n; j++) {
        mini = min(mini, arr[j]);
        sum = (sum + mini) % MOD;
      }
    }

    return (int)sum;
  }

  // TC: ~O(N), SC: ~O(N)
  int sumSubarrayMinsOpt(vector<int> &arr) {
    int n = arr.size();
    long long sum = 0;
    vector<int> left(n), right(n);

    stack<int> leftStack, rightStack;

    // Finding stacks on the left side in which our current el would be the
    // samlleset
    for (int i = 0; i < n; i++) {
      while (!leftStack.empty() && arr[leftStack.top()] > arr[i]) {
        leftStack.pop();
      }

      left[i] = (leftStack.empty()) ? i + 1 : i - leftStack.top();
      leftStack.push(i);
    }

    // Finding stacks on the right side in which our current el would be the
    // samlleset
    for (int i = n - 1; i >= 0; i--) {
      while (!rightStack.empty() && arr[rightStack.top()] >= arr[i]) {
        rightStack.pop();
      }

      right[i] = (rightStack.empty()) ? n - i : rightStack.top() - i;

      rightStack.push(i);
    }

    // calculating total sum using the count of subarrays in which current el
    // would be smalled from left and right
    for (int i = 0; i < n; i++) {
      sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;
    }

    return (int)sum;
  }
};

int main() {}
