#include <vector>
#include <algorithm>

using namespace std;

bool canPerformOpWithPenalty(vector<int>& nums, int op, int penalty) {
  int count = 0;
  for (auto& i : nums) {
    count += (i - 1) / penalty;
  }

  return count <= op;
}

int minimumSize(vector<int>& nums, int maxOperations) {
  int low = 1, high = *max_element(nums.begin(), nums.end());
  int ans = 0;

  while (low <= high) {
    int mid = (low + high) >> 1;
    if (canPerformOpWithPenalty(nums, maxOperations, mid)) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return ans;
}
