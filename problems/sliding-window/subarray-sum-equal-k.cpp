#include <vector>

using namespace std;

// BRUTE FORCE APPROACH - TLE
// O(n^2) time complexity and O(1) space complexity
int subarraySum(vector<int>& nums, int k) {
  int n = nums.size();
  int count = 0;

  for (int i = 0; i < n; i++) {
    int sum = nums[i];

    if (sum == k) {
      count++;
    }

    for (int j = 0; j < n; j++) {
      sum += nums[j];

      if (sum == k) {
        count++;
      }
    }
  }

  return count;
}

// Optimal approach - Sliding window
// O(n) time complexity and O(n) space complexity
int subarraySumSlidingWindow(vector<int>& nums, int k) {
  int n = nums.size();
  int currSum = 0;
  int left = 0, right = 0;
  int count = 0;

  if (n == 1)
    if (nums[0] != k) return 0;
    else return 1;

  while (right < n) {
    currSum += nums[right];

    if (currSum < k) right++;
    else {
      while (currSum >= k) {
        if (currSum == k) count++;
        currSum -= nums[left];
        left++;
      }
      right++;
    }
  }

  return count;
}

// Best Solution - Prefix Sum
int subarraySumPrefixSum(vector<int>& nums, int k) {
  unordered_map<int, int> mp;
  int sum = 0, ans = 0;
  mp[sum] = 1;
  for (auto it : nums) {
    sum += it;
    int find = sum - k;
    if (mp.find(find) != mp.end()) {
      ans += mp[find];
    }
    mp[sum]++;
  }
  return ans;
}
