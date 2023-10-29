#include <deque>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
  vector<long long> result;

  for (int i = 0; i <= N - K; i++) {
    bool foundNegative = false;

    for (int j = 0; j < K; j++) {
      if (A[i + j] < 0) {
        result.push_back(A[i + j]);
        foundNegative = true;
        break;
      }
    }

    if (!foundNegative) {
      result.push_back(0);
    }
  }

  return result;
}

vector<long long> printFirstNegativeIntegerSlidingWindow(long long int A[], long long int N, long long int K) {
  vector<long long> result;
  deque<long long> negativeIndicesWindow;

  for (int i = 0; i < N; i++) {
    if (A[i] < 0) {
      negativeIndicesWindow.push_back(i);
    }

    while (!negativeIndicesWindow.empty() && negativeIndicesWindow.front() < i - K + 1) {
      negativeIndicesWindow.pop_front();
    }

    if (i >= K - 1) {
      if (!negativeIndicesWindow.empty()) {
        result.push_back(A[negativeIndicesWindow.front()]);
      }
      else {
        result.push_back(0);
      }
    }
  }

  return result;
}


int main() {
  long long int A[] = { 12, -1, -7, 8, -15, 30, 16, 28 };
  long long int K = 3;

  vector<long long> result = printFirstNegativeIntegerSlidingWindow(A, 8, K);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  cout << endl;

  long long int B[] = { -8, 2, 3, -6, 10 };
  long long int M = 2;

  vector<long long> result2 = printFirstNegativeIntegerSlidingWindow(B, 5, M);

  for (int i = 0; i < result2.size(); i++) {
    cout << result2[i] << " ";
  }
}
