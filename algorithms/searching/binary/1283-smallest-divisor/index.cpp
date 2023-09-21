#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSumSmallerOrEqual(vector<int>& nums, int threshold, int divisor) {
  int sum = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    sum += ceil((double)(nums[i]) / (double)(divisor));
  }

  return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
  int n = nums.size();
  if (n > threshold) return -1;
  int low = 1, high = *max_element(nums.begin(), nums.end());


  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (isSumSmallerOrEqual(nums, threshold, mid)) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return low;
}


int main() {
  // Test case 1
  vector<int> nums1 = { 1,2,5,9 };
  int threshold1 = 6;
  int result1 = smallestDivisor(nums1, threshold1);
  cout << "Test case 1: " << result1 << endl;

  return 0;
}
