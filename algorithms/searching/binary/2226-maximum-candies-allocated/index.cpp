#include <iostream>
#include <vector>

using namespace std;

//for fast io
static int fast_io = []()
  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
  }();

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  class Solution {
    bool check(vector<int>& candies, int mid, long long& k) {
      if (mid == 0) return true;

      long long int count = 0;
      for (int i = 0; i < candies.size(); i++) {
        int temp = candies[i] / mid;
        count = count + temp;
      }
      if (count >= k) return true;

      return false;
    }

  public:
    int maximumCandies(vector<int>& candies, long long k) {
      int low = 0, high = *max_element(candies.begin(), candies.end());
      int ans = 0;

      while (low <= high) {
        int mid = (low + ((high - low) / 2));
        if (check(candies, mid, k)) {
          if (mid > ans) ans = mid;
          low = mid + 1;
        }
        else {
          high = mid - 1;
        }
      }

      return ans;
    }
  };
