#include<vector>
#include<iostream>
#include<string>

using namespace std;


// TC: O(n)
// SC: O(1)
double myPowBruteForce(double x, int n) {
  // Base case for 0
  if (n == 0) {
    return 1.0;
  }
  long nn = n;

  // CASE: When n is negative, removing the negative would make x to 1/x and negative n would become positive n.
  if (n < 0) {
    x = double(1 / x);
    nn = -1 * nn;
  }

  double ans = x;

  for (int i = 1; i < nn; i++) {
    ans = ans * x;
  }

  return ans;
}

// TC: log(n)
double myPow(double x, int n) {
  double ans = 1.0;
  long nn = n;

  if (nn < 0) nn = -1 * nn;

  while (nn > 0) {
    if (nn % 2 == 1) {
      ans = ans * x;
      nn = nn - 1;
    }
    else {
      x = x * x;
      nn = nn / 2;
    }
  }

  if (n < 0) ans = double(1.0) / double(ans);

  return ans;
}

// TC: O(log n)
// SC: O(log n) due to the recursion stack
double myPowRecursive(double x, int n) {
  if (n == 0) {
    return 1.0;
  }

  // Calculate half power
  double halfPower = myPow(x, n / 2);

  // Multiply for even power, multiply and divide by x for odd power
  if (n % 2 == 0) {
    return halfPower * halfPower;
  }
  else {
    return (n > 0) ? x * halfPower * halfPower : (1.0 / x) * halfPower * halfPower;
  }
}


int main() {}
