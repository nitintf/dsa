#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/


class Solution {
  bool isMountain(int a, int b, int c) {
    return a < b && b > c;
  }

public:
  int longestMountain(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp1(n, 1), dp2(n, 1);

    for (int ind = 1; ind < n; ind++) {
      if (arr[ind] > arr[ind - 1]) {
        dp1[ind] = 1 + dp1[ind - 1];
      }
    }

    for (int ind = n - 2; ind >= 0; ind--) {
      if (arr[ind] > arr[ind + 1]) {
        dp2[ind] = 1 + dp2[ind + 1];
      }
    }

    int maxi = 0;

    for (int i = 0; i < n; i++) {
      if (dp1[i] > 1 && dp2[i] > 1) {
        maxi = max(dp1[i] + dp2[i] - 1, maxi);
      }
    }

    return maxi;
  }

  int longestMountainWith2Pointers(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
      if (isMountain(arr[i - 1], arr[i], arr[i + 1])) {
        int left = i - 1;
        int right = i + 1;

        while (left > 0 && arr[left] > arr[left - 1]) {
          left--;
        }

        while (right < n - 1 && arr[right] > arr[right + 1]) {
          right++;
        }

        ans = max(ans, right - left + 1);
      }
    }

    return ans;
  }
};

int main() {}
