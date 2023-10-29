#include <vector>
#include <iostream>

using namespace std;

int minSubarraySum(vector<int>& arr, int target) {
  int n = arr.size();
  int currSum = 0;
  int left = 0;
  int minLen = n + 1;

  for (int right = 0; right < n; right++) {
    currSum += arr[right];

    while (currSum >= target) {
      minLen = min(minLen, right - left + 1);
      currSum -= arr[left];
      left++;
    }
  }

  return minLen == n + 1 ? 0 : minLen;
}
