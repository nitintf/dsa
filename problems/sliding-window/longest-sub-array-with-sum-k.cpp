#include <map>
#include <algorithm>

int lenOfLongSubarr(int A[], int N, int K)
{
  std::unordered_map<int, int> sumToIndex;
  int maxLen = 0;
  int currentSum = 0;

  for (int i = 0; i < N; i++) {
    currentSum += A[i];

    if (currentSum == K) {
      maxLen = i + 1;
    }

    if (sumToIndex.find(currentSum - K) != sumToIndex.end()) {
      maxLen = std::max(maxLen, i - sumToIndex[currentSum - K]);
    }

    if (sumToIndex.find(currentSum) == sumToIndex.end()) {
      sumToIndex[currentSum] = i;
    }
  }

  return maxLen;
}
