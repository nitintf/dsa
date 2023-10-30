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

// TC: O(n)
// SC: O(k)
vector<int> findMaxInSubArrayWithSizeK(vector<int> a, int n, int k) {
  vector<int> result;

  if (k > n) {
    result.push_back(*max_element(a.begin(), a.end()));
    return result;
  }

  deque<int> dq;
  int left = 0, right = 0;

  while (right < n) {
    while (!dq.empty() && dq.back() < a[right]) {
      dq.pop_back();
    }
    dq.push_back(a[right]);

    if (right - left + 1 < k) {
      right++;
    }
    else if (right - left + 1 == k) {
      result.push_back(dq.front());
      if (a[left] == dq.front()) {
        dq.pop_front();
      }
      right++;
      left++;
    }
  }

  return result;
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
