#include <vector>
#include <iostream>
using namespace std;

int findKthNum(vector<int>& nums, int k) {
  int low = 0, high = nums.size() - 1;

  while (low <= high) {
    int mid = (high + low) / 2;
    int missingEls = nums[mid] - (mid + 1);

    if (missingEls < k) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  return low + k;
}

int main() {
  // Test Case 1
  vector<int> nums1 = { 2,3,4,7,11 };
  int k1 = 5;
  int result1 = findKthNum(nums1, k1);
  cout << "Test Case 1: " << result1 << endl;

  // Test Case 2
  vector<int> nums2 = { 2, 3, 6, 8, 9 };
  int k2 = 5;
  int result2 = findKthNum(nums2, k2);
  cout << "Test Case 2: " << result2 << endl;

  // Test Case 3
  vector<int> nums3 = { 1, 3, 4, 7, 9 };
  int k3 = 1;
  int result3 = findKthNum(nums3, k3);
  cout << "Test Case 3: " << result3 << endl;

  return 0;
}
