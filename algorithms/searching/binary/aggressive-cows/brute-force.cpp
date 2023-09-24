// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559

#include <vector>
#include <iostream>

using namespace std;

bool canWePlaceCows(vector<int>& stalls, int k, int distance) {
  int cowsPlaced = 1;
  int prevPosition = stalls[0];

  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] - prevPosition >= distance) {
      cowsPlaced++;
      prevPosition = stalls[i];
    }

    if (cowsPlaced >= k) return true;
  }
  return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
  int n = stalls.size();
  sort(stalls.begin(), stalls.end());

  int limit = stalls[n - 1] - stalls[0];
  for (int i = 0; i < n; i++) {
    if (canWePlaceCows(stalls, k, i) == false) {
      return i - 1;
    }
  }

  return limit;
}

int main() {
  // Test case 1
  vector<int> stalls1 = { 1, 2, 3 };
  int k1 = 2;
  int result1 = aggressiveCows(stalls1, k1);
  cout << "Test Case 1: " << result1 << endl;

  // Test case 2
  vector<int> stalls2 = { 0, 3, 4, 7, 10, 9 };
  int k2 = 4;
  int result2 = aggressiveCows(stalls2, k2);
  cout << "Test Case 2: " << result2 << endl;

  // Test case 3
  vector<int> stalls3 = { 4, 2, 1, 3, 6 };
  int k3 = 2;
  int result3 = aggressiveCows(stalls3, k3);
  cout << "Test Case 3: " << result3 << endl;

  return 0;
}
