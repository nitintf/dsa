#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:

  // Space optimized O(n), O(1)
  int robSpaceOptimized(vector<int>& nums) {
    int n = nums.size();
    int prev = 0;
    int curr = nums[0];

    for (int i = 1; i < n;i++) {
      int pick = nums[i];
      if (i - 2 >= 0) {
        pick += prev;
      }
      int skip = curr;
      prev = curr;
      curr = max(pick, skip);
    }

    return curr;
  }

  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> nums1(nums.begin(), nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());

    return max(robSpaceOptimized(nums1), robSpaceOptimized(nums2));
  }
};

int main() {
  Solution s;
  vector<int> nums = { 2, 3, 2 };
  cout << s.rob(nums) << endl;
  return 0;
}
