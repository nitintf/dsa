#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
Bitnoc Subseq- LIS(longest increasing sub sequence), LDS(longest decreasing sub sequqence), OR
  - find the subseq DP from the right side and then find the subseq DP from th left side
  - the adding the elements from the DP1 and DP2 at the same index and subtracting 1 from them would give the Bitonic array
*/

class Solution {
public:
  int longestBitonicSubSeq(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n, 1), dp2(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j] && dp1[j] + 1 > dp1[i]) {
          dp1[i] = dp1[j] + 1;
        }
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= i; j--) {
        if (nums[i] > nums[j] && dp2[j] + 1 > dp2[i]) {
          dp2[i] = dp2[j] + 1;
        }
      }
    }

    int maxi = 0;

    for (int i = 0; i < n; i++) {
      int diff = (dp1[i] + dp2[i]) - 1;
      maxi = max(maxi, diff);
    }

    return maxi;
  }
};

int main() {}
