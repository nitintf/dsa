#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  bool subsetSumToK(vector<int>& arr, int k, int n) {
    vector<bool> prev(k + 1, false);;
    prev[0] = true;

    if (arr[0] <= k)
      prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
      vector<bool> curr(k + 1, false);
      curr[0] = true;
      for (int target = 1; target <= k; target++) {
        bool notTake = prev[target];
        bool take = false;
        if (target >= arr[i]) {
          take = prev[target - arr[i]];
        }
        curr[target] = take || notTake;
      }

      prev = curr;
    }

    return prev[k];
  }

public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;

    for (int i = 0; i < n; i++) totalSum += nums[i];

    if (totalSum % 2 == 1) return false;
    int targetSum = totalSum / 2;


    return subsetSumToK(nums, targetSum, n);
  }
};

int main() {}
