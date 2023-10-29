#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// TC O(n) SC O(n)
long long maxSubArraySum(vector<int> nums, int k) {
  int n = nums.size();
  long long sum = 0, ans = 0;
  unordered_map<int, int> distinctEls;

  for (int i = 0; i < n; i++) {
    if (distinctEls.count(nums[i]) == 0) {
      sum += nums[i];
    }

    distinctEls[nums[i]]++;

    if (distinctEls.size() == k) {
      ans = max(ans, sum);
    }

    int leftMostIdx = i - k + 1;
    if (leftMostIdx >= 0) {
      distinctEls[nums[leftMostIdx]]--;

      if (distinctEls[nums[leftMostIdx]] == 0) {
        sum -= nums[leftMostIdx];
        distinctEls.erase(nums[leftMostIdx]);
      }
    }
  }

  return ans;
}


int main() {
  vector<int> nums = { 1, 5 ,4 ,2 ,9, 9, 9 };
  int k = 3;

  long long ans = maxSubArraySum(nums, k);

  cout << "Ans : " << ans << endl;
  return 0;
}
