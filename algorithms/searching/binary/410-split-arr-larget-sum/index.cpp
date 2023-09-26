#include <vector>
#include <numeric>

using namespace std;

bool isValid(vector<int>& nums, int k, int limit) {
  int sum = 0;
  int subArrCount = 1;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (sum + nums[i] <= limit) {
      sum += nums[i];
    }
    else {
      subArrCount++;
      sum = nums[i];
    }
  }
  return subArrCount <= k;
}

int splitArray(vector<int>& nums, int k) {
  int low = *max_element(nums.begin(), nums.end());
  int high = accumulate(nums.begin(), nums.end(), 0);

  while (low <= high) {
    int mid = (high + low) / 2;

    if (isValid(nums, k, mid)) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return low;
}
