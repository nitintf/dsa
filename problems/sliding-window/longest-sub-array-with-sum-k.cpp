#include <map>
#include <algorithm>

using namespace std;

int lenOfLongSubarr(int A[], int N, int K)
{
  unordered_map<int, int> sumToIndex;
  int maxLen = 0;
  int currentSum = 0;

  for (int i = 0; i < N; i++) {
    currentSum += A[i];

    if (currentSum == K) {
      maxLen = i + 1;
    }

    if (sumToIndex.find(currentSum - K) != sumToIndex.end()) {
      maxLen = max(maxLen, i - sumToIndex[currentSum - K]);
    }

    if (sumToIndex.find(currentSum) == sumToIndex.end()) {
      sumToIndex[currentSum] = i;
    }
  }

  return maxLen;
}
