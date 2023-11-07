#include <vector>

using namespace std;

// Brute Force Approach
// Intuition:
// The idea is to consider all subarrays one by one and check the sum of every subarray.For this we can run two loops : the outer loop picks a starting point i and the inner loop tries all subarrays starting from i.

// Implementation :
//   Steps :
//   Traverse the array from start to end.
//   From every index start another loop from i to the end of the array to get all subarrays starting from i, and keep a variable currentSum to calculate the sum of every subarray.
//   For every index in inner loop update currentSum = currentSum + arr[j]
//   If the currentSum is equal to the given sum then return i as left index and j as the right index.

// O(n^2) time complexity and O(1) space complexity
vector<int> subarraySum(vector<int>arr, int n, long long s)
{
  vector<int>ans;
  bool bl = false;

  for (int i = 0; i < n; i++) {
    int sum = arr[i];

    if (sum == s) {
      ans.push_back(i + 1);
      ans.push_back(i + 1);
      bl = true;
      break;
    }
    else {
      for (int j = i + 1; j < n; j++) {
        sum += arr[j];

        if (sum == s) {
          ans.push_back(i + 1);
          ans.push_back(j + 1);
          bl = true;
          break;
        }
      }
      if (bl) break;
    }
  }

  if (bl) return ans;
  return { -1 };
}

vector<int> subarraySumSlidingWindow(vector<int>arr, int n, long long s) {
  int last = 0;
  int start = 0;
  unsigned long long sum = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];

    if (sum >= s) {
      last = i;

      while (sum > s && start < last) {
        sum -= arr[start];
        ++start;
      }

      if (sum == s) {
        return { start + 1, last + 1 };
      }
    }
  }

  return { -1 };
}
