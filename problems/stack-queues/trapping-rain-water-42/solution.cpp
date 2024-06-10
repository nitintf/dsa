#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
Notes
*/

class Solution {
private:
  int right(int idx, int n, vector<int> &height) {
    int maxx = height[idx];

    for (int i = idx; i < n; i++) {
      maxx = max(maxx, height[i]);
    }

    return maxx;
  }

  int left(int idx, vector<int> &height) {
    int maxx = height[idx];

    for (int i = idx; i >= 0; i--) {
      maxx = max(maxx, height[i]);
    }

    return maxx;
  }

public:
  // brute force approach, we find the max height on left and right find the min
  // of that and subtract the current height thats the unit of water we can
  // store at that index, TC: O(n*n), SC: O(1)
  int trap(vector<int> &height) {
    int totalWater = 0;
    int n = height.size();

    for (int i = 0; i < n; i++) {
      totalWater += min(left(i, height), right(i, n, height)) - height[i];
    }

    return totalWater;
  }

  // TODO: Prefix & Suffix
  // TC: O(n), SC: O(2N)
  int trapBetter(vector<int> &height) {}

  // Two pointers
  // TC: O(n), SC: O(1)
  int trapOptimal(vector<int> &h) {
    int totalWater = 0;
    int n = h.size();
    int left = 0, leftMax = 0, right = n - 1, rightMax = 0;

    while (left <= right) {
      if (h[left] <= h[right]) {
        if (h[left] >= leftMax) {
          leftMax = h[left];
        } else {
          totalWater += leftMax - h[left];
        }
        left++;
      } else {
        if (h[right] >= rightMax) {
          rightMax = h[right];
        } else {
          totalWater += rightMax - h[right];
        }
        right--;
      }
    }

    return totalWater;
  }
};

int main() {}
