#include <vector>
#include <algorithm>

using namespace std;

bool isEqualForce(vector<int>& position, int m, int limit) {
  int k = 1;
  int prevPosition = position[0];

  for (int i = 1; i < position.size(); i++) {
    if (position[i] - prevPosition >= limit) {
      k++;
      prevPosition = position[i];
    }
    if (k >= m) return true;
  }

  return false;
}

int maxDistance(vector<int>& positions, int m) {
  int ans = 0;
  int low = 0, high = *max_element(positions.begin(), positions.end());
  sort(positions.begin(), positions.end());
  while (low <= high) {
    int mid = (low + high) >> 1;

    if (isEqualForce(positions, m, mid)) {
      ans = mid;
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  return ans;

}
