#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool canDistribute(int n, vector<int>& quantities, int m) {
  int sum = 0;
  int si = quantities.size();

  for (int i = 0; i < si; i++) {
    sum += ceil((double)quantities[i] / (double)m);
  }

  return sum > n;
}

int minimizedMaximum(int n, vector<int>& quantities) {
  int l = 1, r = *max_element(quantities.begin(), quantities.end());

  while (l <= r) {
    int mid = (l + r) / 2;

    if (canDistribute(n, quantities, mid)) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  return l;
}


int main() {
  // Test case inputs
  int n = 6;
  vector<int> quantities = { 11, 6 };

  // Call the function and store the result
  int result = minimizedMaximum(n, quantities);

  // Print the result
  cout << "Result: " << result << endl;

  return 0;
}
