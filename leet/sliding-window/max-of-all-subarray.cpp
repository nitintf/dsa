#include <deque>
#include <vector>
#include <iostream>

using namespace std;

vector<int> maxOfSubArrays(int arr[], int n, int k) {
  vector<int> ans;

  for (int i = 0; i <= n - k; i++) {
    int max = arr[i];
    for (int j = 1; j < k; j++) {
      if (arr[i + j] > max) {
        max = arr[i + j];
      }
    }

    ans.push_back(max);
  }

  return ans;
}

vector<int> maxOfSubArraysSlidingWindow(int arr[], int n, int k) {
  vector<int> ans;
  deque<int> dq;

  int maxEl = 0;
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && dq.front() < i - k + 1) {
      dq.pop_front();
    }

    while (!dq.empty() && arr[dq.back()] < arr[i]) {
      dq.pop_back();
    }

    dq.push_back(i);

    if (i >= k - 1) {
      ans.push_back(arr[dq.front()]);
    }
  }

  return ans;
}


int main() {
  int arr[] = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
  int k = 3;

  vector<int> ans = maxOfSubArraysSlidingWindow(arr, 9, k);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
