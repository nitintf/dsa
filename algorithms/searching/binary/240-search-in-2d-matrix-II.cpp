#include <vector>

using namespace std;


// --------------------- Brute Force ---------------------
// Time: O(n*m)
// Space: O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == target) {
        return true;
      }
    }
  }

  return false;
}


// --------------------- Binary Search ---------------------
// Time: O(nlogm)
// Space: O(1)
bool searchMatrixBS(vector<vector<int>>& matrix, int target) {
  int n = matrix.size();

  for (int i = 0; i < n; i++) {
    int low = 0, high = matrix[0].size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (matrix[i][mid] == target) {
        return true;
      }
      else if (matrix[i][mid] > target) {
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }
  }

  return false;
}

// ---------------------- Optimal Solution ----------------------
// Time: O(n+m)
// Space: O(1)
bool searchMatrixOptimal(vector<vector<int>>& matrix, int target) {
  int n = matrix.size();
  int row = 0, col = matrix[0].size() - 1;

  while (row < n && col >= 0) {
    if (matrix[row][col] == target) {
      return true;
    }
    else if (matrix[row][col] > target) {
      col--;
    }
    else {
      row++;
    }
  }

  return false;
}
