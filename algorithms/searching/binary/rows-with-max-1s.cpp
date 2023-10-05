#include <vector>

using namespace std;


// --------------- Brute Force ---------------
// TC = O(n*m)
// SC = O(1)

int rowWithMax1sBruteForce(vector<vector<int>>& matrix, int n, int m)
{
  int maxCount = 0;
  int minR = -1;
  for (int i = 0; i <= n - 1; i++) {
    int count = 0;
    for (int j = 0; j <= m - 1; j++) {
      count += matrix[i][j];
    }
    if (count > maxCount) {
      maxCount = count;
      minR = i;
    }
  }

  return minR;
}

// --------------- Optimized (BS) ----------------
// TC = O(nlogm)
// SC = O(1)

int lowerBound(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2;
    // maybe an answer
    if (arr[mid] >= x) {
      ans = mid;
      //look for smaller index on the left
      high = mid - 1;
    }
    else {
      low = mid + 1; // look on the right
    }
  }
  return ans;
}

int rowWithMax1s(vector<vector<int>>& matrix, int n, int m)
{
  int max_count = 0;
  int index = -1;
  int ans = m;
  for (int i = 0; i <= n - 1; i++) {
    int cnt = m - lowerBound(matrix[i], m, 1);
    if (cnt > max_count) {
      max_count = cnt;
      index = i;
    }
  }

  return index;
}
