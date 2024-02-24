#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n), temp;

    sort(nums.begin(), nums.end());

    int lastIndex = 0, maxi = 1;

    for (int i = 0; i < n; i++) {
      hash[i] = i;
      for (int j = 0; j < i; j++) {
        if ((nums[i] % nums[j] == 0) && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          hash[i] = j;d
        }
      }

      if (dp[i] > maxi) {
        maxi = dp[i];
        lastIndex = i;
      }
    }

    temp.push_back(nums[lastIndex]);

    while (hash[lastIndex] != lastIndex) {
      lastIndex = hash[lastIndex];
      temp.push_back(nums[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    return temp;

  }
};

int main() {}
