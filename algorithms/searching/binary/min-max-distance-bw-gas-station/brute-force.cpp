#include <vector>
#include <iostream>

using namespace std;

double minimiseMaxDistance(vector<int>& a, int k) {
  int n = a.size();
  vector<int> b(n - 1, 0);

  for (int gasStation = 1; gasStation <= k; gasStation++) {
    long double maxDistance = -1;
    int maxIndex = -1;

    for (int i = 0; i < n - 1; i++) {
      long double diff = a[i + 1] - a[i];
      long double sectionLength = diff / (long double)(b[i] + 1);
      if (sectionLength > maxDistance) {
        maxDistance = sectionLength;
        maxIndex = i;
      }
    }

    b[maxIndex]++;
  }

  long double maxDistance = -1;

  for (int i = 0; i < n - 1; i++) {
    long double diff = a[i + 1] - a[i];
    long double sectionLength = diff / (long double)(b[i] + 1);
    if (sectionLength > maxDistance) {
      maxDistance = sectionLength;
    }
  }

  return maxDistance;
}
