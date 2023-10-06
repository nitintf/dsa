#include <vector>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();
  vector<int> res;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool isPeak = true;

      if (i > 0 && mat[i][j] <= mat[i - 1][j]) {
        isPeak = false;
      }
      if (i < n - 1 && mat[i][j] <= mat[i + 1][j]) {
        isPeak = false;
      }
      if (j > 0 && mat[i][j] <= mat[i][j - 1]) {
        isPeak = false;
      }
      if (j < m - 1 && mat[i][j] <= mat[i][j + 1]) {
        isPeak = false;
      }

      if (isPeak) {
        return { i, j };
      }
    }
  }

  return res;
}

// ---------------------------- Optimal Solution (BS) ---------------------------

int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
  int maxValue = -1;
  int index = -1;
  for (int i = 0; i < n; i++) {
    if (mat[i][col] > maxValue) {
      maxValue = mat[i][col];
      index = i;
    }
  }

  return index;
}

vector<int> findPeakGridBS(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();
  int low = 0, high = m - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int maxIndex = findMaxIndex(mat, n, mat[0].size(), mid);

    int left = mid - 1 >= 0 ? mat[maxIndex][mid - 1] : -1;
    int right = mid + 1 < m ? mat[maxIndex][mid + 1] : -1;

    if (mat[maxIndex][mid] > left && mat[maxIndex][mid] > right) {
      return { maxIndex, mid };
    }
    else if (mat[maxIndex][mid] < left) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return { -1, -1 };
}
