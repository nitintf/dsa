#include<vector>
#include<iostream>
#include<string>

using namespace std;

void subarraysWithSumKHelper(vector<int>& nums, int index, int& sum, vector<int>& ds, int k) {
  if (sum == k) {
    for (auto& num : ds) {
      cout << num << " ";
    }
    cout << endl;
  }

  // handle pick case
  sum += nums[index];
  ds.push_back(nums[index]);
  subarraysWithSumKHelper(nums, index + 1, sum, ds, k);

  // case for when cotrols come back
  sum -= nums[index];
  ds.pop_back();
  subarraysWithSumKHelper(nums, index + 1, sum, ds, k);
}

void subarraysWithSumK(vector<int>& nums, int k) {
  int sum = 0;
  vector<int> ds;
  subarraysWithSumKHelper(nums, 0, sum, ds, k);
}

vector<vector<int>> subarraysWithSumK_2Pointers(vector<int>& nums, int k) {
  int start = 0, end = 0;
  int sum = 0;
  vector<vector<int>> result;

  while (start < nums.size()) {
    while (end < nums.size() && (sum + nums[end] <= k)) {
      sum += nums[end];
      end++;
    }

    if (sum == k) {
      vector<int> temp;
      for (int i = start; i < end; i++) {
        temp.push_back(nums[i]);
      }
      result.push_back(temp);
    }

    sum -= nums[start];
    start++;
  }

  return result;
}

int main() {
  vector<int> nums = { 1, 2, 3, 1, 1, 1 };
  int k = 3;
  subarraysWithSumK(nums, k);
  return 0;
}
