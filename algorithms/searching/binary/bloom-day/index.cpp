#include "vector"
#include "iostream"
using std::vector;

int findMin(vector<int>& nums)
{
  int n = nums.size();
  int min = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    if (nums[i] < min)
    {
      min = nums[i];
    }
  }

  return min;
}

int findMax(vector<int>& nums)
{
  int n = nums.size();
  int max = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if (nums[i] > max)
    {
      max = nums[i];
    }
  }

  return max;
}

bool canBloom(vector<int>& bloomDay, int day, int m, int k)
{
  int counter = 0;
  int noOfBlooms = 0;
  int n = bloomDay.size();

  for (int i = 0; i < n; i++)
  {
    if (day >= bloomDay[i])
    {
      counter++;
    }
    else
    {
      noOfBlooms += counter / k;
      counter = 0;
    }
  }

  noOfBlooms += counter / k;
  return noOfBlooms >= m;
}

int minDays(vector<int>& bloomDay, int m, int k)
{
  int low = findMin(bloomDay), high = findMax(bloomDay);

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (canBloom(bloomDay, mid, m, k))
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
  vector<int> bloomDays = { 1, 10, 3, 10, 2 };
  int ans = minDays(bloomDays, 3, 1);

  std::cout << ans << std::endl;

  bloomDays = { 7, 7, 7, 7, 12, 7, 7 };
  ans = minDays(bloomDays, 2, 3);
  std::cout << ans << std::endl;
}
