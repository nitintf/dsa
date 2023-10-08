#include <vector>

using namespace std;

bool canCompleteTripInTime(vector<int>& time, int totalTrips, long long maxTime) {
  long long trips = 0;
  for (auto& t : time) {
    trips += maxTime / t;
  }

  return trips >= totalTrips;
}


// TC: nlogk
// SC: O(1)
long long minimumTime(vector<int>& time, int totalTrips) {
  long long low = 1, high = 1e14;

  while (low <= high) {
    long long mid = (low + high) >> 1;

    if (canCompleteTripInTime(time, totalTrips, mid)) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return low;
}


// BRUTE FORCE

long long minimumTimeBruteForce(vector<int>& time, int totalTrips) {
  int count = 0;
  int trips = 0;

  for (auto& t : time) {

  }
}
