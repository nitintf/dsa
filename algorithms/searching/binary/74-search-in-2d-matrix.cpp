#include <vector>

using namespace std;

// -------------------- Brute Force --------------------
// TC: O(n*m)
// SC: O(1)
bool searchMatrixBruteForcs(vector<vector<int>>& matrix, int target) {
  int n = matrix.size(), m = matrix[0].size();

  //traverse the matrix:
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == target)
        return true;
    }
  }
  return false;
}

// -------------------- Binary Search --------------------
// TC: O(log(n*m))
// SC: O(1)

int binarySearch(vector<vector<int>>& arr, int target) {
  int n = arr.size(), m = arr[0].size();

  int low = 0, high = n * m - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int row = mid / m, col = mid % m;
    if (arr[row][col] == target) return true;
    else if (arr[row][col] < target) low = mid + 1;
    else high = mid - 1;
  }
  return false;
}
