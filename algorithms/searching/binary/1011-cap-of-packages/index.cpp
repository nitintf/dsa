#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool possible(vector<int>& weights, int days, int capacity) {
  int load = 0;
  int totalDays = 1;
  int n = weights.size();

  for (int i = 0; i < n; i++) {
    if (load + weights[i] > capacity) {
      totalDays += 1;
      load = weights[i];
    }
    else {
      load += weights[i];
    }
  }

  return totalDays <= days;
}

int findDays(vector<int>& weights, int days) {
  int low = *max_element(weights.begin(), weights.end());
  int high = accumulate(weights.begin(), weights.end(), 0);

  while (low <= high) {
    int mid = (low + high) / 2;

    if (possible(weights, days, mid)) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return low;
}

int main() {
  vector<int> weights1 = { 1,2,3,4,5,6,7,8,9,10 };
  int days1 = 5;
  int expected1 = 15;
  int actual1 = findDays(weights1, days1);
  cout << "Expected: " << expected1 << " Actual: " << actual1 << endl;


  vector<int> weights2 = { 3,2,2,4,1,4 };
  int days2 = 3;
  int expected2 = 6;
  int actual2 = findDays(weights2, days2);
  cout << "Expected: " << expected2 << " Actual: " << actual2 << endl;
}
