#include <vector>
#include <iostream>
#include <algorithm>

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

int findMaximum(std::vector<int> &v)
{
  int maxi = INT_MIN;
  int n = v.size();

  for (int i = 0; i < n; i++)
  {
    maxi = std::max(maxi, v[i]);
  }

  return maxi;
}

int calculateTotalHrs(std::vector<int> &v, int k)
{
  int totalHrs = 0;
  int n = v.size();

  for (int i = 0; i < n; i++)
  {
    totalHrs += ceil((double)v[i] / k);
  }
  return totalHrs;
}

int minEatingSpeed(std::vector<int> &piles, int h)
{
  int low = 1, high = findMaximum(piles);

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int totalHrs = calculateTotalHrs(piles, mid);

    if (totalHrs <= h)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return low;
}

int main()
{
  // [3, 6, 7, 11]
  std::vector<int> nums;
  nums.push_back(805306368);
  nums.push_back(805306368);
  nums.push_back(805306368);

  int hrs = 1000000000;
  int result = minEatingSpeed(nums, hrs);

  std::cout << result << std::endl;
}
