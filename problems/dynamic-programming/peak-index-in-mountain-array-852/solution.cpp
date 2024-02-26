#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Solution {
  bool isPeakValue(int a, int b, int c) { return b > a && b > c; }

public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();

    int left = 0, right = n - 1;

    while (left <= right) {
      int mid = (left + right) / 2;

      int leftMost = -1e9, rightMost = -1e9;

      if (mid - 1 >= 0) leftMost = arr[mid - 1];
      if (mid + 1 < n) rightMost = arr[mid + 1];

      if (isPeakValue(leftMost, arr[mid], rightMost)) {
        return mid;
      }
      else if (leftMost > arr[mid]) {
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }

    return -1;
  }
};

int main() {}
