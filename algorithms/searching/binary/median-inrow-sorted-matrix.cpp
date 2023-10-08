// https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473
#include <vector>
#include <iostream>

using namespace std;


// ------------------------ Brute Force (Sorting - Merge Sort) ------------------------
vector<int> merge(vector<int> left, vector<int> right) {
  int i = 0, j = 0;
  vector<int> merged;

  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      merged.push_back(left[i]);
    }
    else {
      merged.push_back(right[j]);
    }
  }

  while (i < left.size()) {
    merged.push_back(left[i]);
  }

  while (j < right.size()) {
    merged.push_back(right[j]);
  }

  return merged;
}

vector<int> mergeSort(vector<int> arr) {
  // Base case only array length is 1
  if (arr.size() == 1) {
    return arr;
  }

  int mid = arr.size() / 2;
  vector<int> left;
  vector<int> right;
  for (int i = 0; i < mid; i++) {
    left.push_back(arr[i]);
  }
  for (int i = mid; i < arr.size(); i++) {
    right.push_back(arr[i]);
  }

  vector<int> sortedLeft = mergeSort(left);
  vector<int> sortedRight = mergeSort(right);

  return merge(sortedLeft, sortedRight);
}

// TC: O(n*m + n*m log(m*n))
// SC: O(n*m)
int findMedianInRowSortedMatrix(vector<vector<int>> mat) {
  int n = mat.size();
  int m = mat[0].size();
  int medianIdx = (n * m) / 2;
  vector<int> res;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res.push_back(mat[i][j]);
    }
  }

  // vector<int> sorted = mergeSort(res);
  sort(res.begin(), res.end());
  return res[medianIdx];
}


// ------------------------ Optimal Solution (Binary Search) ------------------------

int upperBound(vector<int> arr, int val, int m) {
  int low = 0;
  int high = m - 1;
  int ans = m;

  while (low <= high) {
    int mid = (low + high) >> 1;

    if (arr[mid] > val) {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }
  return ans;
}

int countSmallOrEqual(vector<vector<int>> mat, int n, int m, int val) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += upperBound(mat[i], val, m);
  }

  return cnt;
}

// TC: O(n*log(m))
// SC: O(1)
int findMedianInRowSortedMatrixBS(vector<vector<int>> mat) {
  int low = INT_MIN;
  int high = INT_MAX;
  int n = mat.size();
  int m = mat[0].size();

  for (int i = 0; i < n; i++) {
    low = min(low, mat[i][0]);
    high = max(high, mat[i][m - 1]);
  }

  int target = (m * n) / 2;

  while (low <= high) {
    int mid = (low + high) >> 1;
    int smallOrEqual = countSmallOrEqual(mat, n, m, mid);
    if (smallOrEqual <= target) low = mid + 1;
    else high = mid - 1;
  }

  return low;
}
