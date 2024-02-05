#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  int ninjaTraininghelper(int day, int task, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (dp[day][task] != -1) {
      return dp[day][task];
    }

    if (day == 0) {
      int maxPoint = 0;
      for (int i = 0; i < 3; i++) {
        if (i != task) {
          maxPoint = max(maxPoint, points[day][i]);
        }
      }
      return dp[day][task] = maxPoint;
    }

    int maxPoint = 0;

    for (int i = 0; i < 3; i++) {
      if (i != task) {
        maxPoint = max(maxPoint, points[day][i] + ninjaTraininghelper(day - 1, i, points, dp));
      }
    }

    return dp[day][task] = maxPoint;
  }

public:
  int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaTraininghelper(n - 1, 3, points, dp);
  }

  int ninjaTrainingTabulation(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2]));
  }
};

int main() {
  int n = 3;
  vector<vector<int>> points = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  Solution solution;
  cout << solution.ninjaTraining(n, points) << endl;
  return 0;
}
