#include <iostream>

// If mid > m = 2
// if mid == m = 1
// if mid < m = 0
int func(int mid, int n, int m)
{
  long long ans = 1;
  for (int i = 0; i < n; i++)
  {
    ans *= mid;
    if (ans > m)
      return 2;
  }
  if (ans == m)
    return 1;
  return 0;
}

int NthRoot(int n, int m)
{
  int low = 1, high = m;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int midN = func(mid, n, m);

    if (midN == 1)
    {
      return mid;
    }
    else if (midN == 0)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int main()
{
  int n = 3;
  int m = 27;
  int result = NthRoot(n, m);
  std::cout << n << "th root of " << m << " is " << result << std::endl;
  return 0;
}
