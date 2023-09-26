#include <vector>
#include <numeric>

using namespace std;

int countStudents(vector<int>& arr, int pages) {
  int n = arr.size();
  int students = 1;
  long long pagesCount = 0;

  for (int i = 0; i < n; i++) {
    if (pagesCount + arr[i] <= pages) {
      pagesCount += arr[i];
    }
    else {
      students++;
      pagesCount = arr[i];
    }
  }

  return students;
}

int findPages(vector<int>& arr, int n, int m) {
  // book allocation impossible:
  if (m > n) {
    return -1;
  }

  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);

  for (int pages = low; pages <= high; pages++) {
    if (countStudents(arr, pages) == m) {
      return pages;
    }
  }

  return low;
}
