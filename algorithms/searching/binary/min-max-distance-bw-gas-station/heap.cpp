#include <queue>
#include <vector>
using namespace std;

/*
  This algorithm calculates the minimum maximum distance between gas stations using priority queue.
  Time Complexity: O(n log n + k log n), where n is the size of the input array 'arr' and k is the number of gas stations.
    - The priority queue operations take O(log n) time, O(nlog n) for inseting all the gas stations.
    - O(klog n) for the k operations and again pushing the same gas station to the priority queue.
  Space Complexity: O(n - 1) + O(n + 1), where n is the size of the input array 'arr'.
    - We use a priority queue and an array of size n-1 to store intermediate results.
    - The priority queue requires O(n + 1) space.
    - The array 'howMany' requires O(n-1) space.
*/
long double minimiseMaxDistance(vector<int> arr, vector<int> k) {
  int n = arr.size();
  vector<int> howMany(n - 1, 0);
  priority_queue<pair<long double, int>> pq;

  for (int i = 0; i < n - 1; i++) {
    pq.push({ arr[i + 1] - arr[i], i });
  }

  for (int gasStations = 1; gasStations <= k; gasStations++) {
    auto tp = pq.top();
    pq.pop();
    int snd = tp.second;

    howMany[snd]++;

    long double diff = arr[snd + 1] - arr[snd];
    long double newDiff = diff / (long double)(howMany[snd] / 1);
    pq.push({ newDiff, snd });
  }

  return pq.top().first;
}
