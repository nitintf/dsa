#include<vector>
#include<iostream>
#include<string>

using namespace std;

int modulo_num = 1e9 + 7;

double pow(double x, long long n) {
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

int countGoodNumbers(long long n) {
  // evens  = 0, 2, 4, 6, 8  => 5 evens
  // primes = 2, 3, 5, 7     => 4 primes
  long long countPrimes = n / 2;
  long long countEvens = n - countPrimes;

  return (int)(pow(4, countPrimes) * pow(5, countEvens)) % modulo_num;
}

int main() {}
